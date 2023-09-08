#include <fs-module/fat/FatFileSystem.hpp>

#include <zephyr/kernel.h>

#include <fs-module/FileSystemFormatException.hpp>
#include <fs-module/FileSystemMountException.hpp>
#include <fs-module/FileSystemUnmountException.hpp>

#define FS_TYPE FS_FATFS
#define DEV_ID "SD:"
#define FLAGS 0

FatFileSystem::FatFileSystem()
    : mp({
          .type = FS_TYPE,
          .fs_data = &fat_fs,
      }) {
}

void FatFileSystem::format() {
#if !CONFIG_FILE_SYSTEM_MKFS
    throw FileSystemFormatException("Unsupported operation. Is it enabled in configuration?");
#endif

    // Existing data on the file system is destroyed upon formatting.
    int ret = fs_mkfs(FS_TYPE, (uintptr_t)DEV_ID, NULL, FLAGS);

    // Success.
    if (ret == 0) {
        return;
    }

    // Failure, no information on what specifically went wrong.
    throw FileSystemFormatException("Unknown error.");
}

void FatFileSystem::mount(const std::string &mount_point) {
    // Current implementation of ELM FAT driver allows only following mount points:
    // "/RAM:","/NAND:","/CF:","/SD:","/SD2:","/USB:","/USB2:","/USB3:" or mount
    // points that consist of single digit, e.g: "/0:", "/1:" and so forth.
    mp.mnt_point = mount_point.c_str();
    int ret = fs_mount(&mp);

    // Success.
    if (ret == 0) {
        return;
    }

    // When file system type has not been registered.
    if (ret == -ENOENT) {
        throw FileSystemMountException("File system type has not been registered.");
    }

    // When not supported by underlying file system driver. When
    // FS_MOUNT_FLAG_USE_DISK_ACCESS is set but driver does not support it.
    if (ret == -ENOTSUP) {
        throw FileSystemMountException("Not supported by underlying file system driver.");
    }

    // If system requires formatting but FS_MOUNT_FLAG_READ_ONLY has been set.
    if (ret == -EROFS) {
        throw FileSystemMountException("System requires formatting but it is read only.");
    }

    if (ret == -EIO) {
        throw FileSystemMountException("I/O error.");
    }

    // Any other unspecific error.
    throw FileSystemMountException("Unknown error.");
}

void FatFileSystem::unmount() {
    int ret = fs_unmount(&this->mp);

    // Success.
    if (ret == 0) {
        return;
    }

    // If no system has been mounted at given mount point.
    if (ret == -EINVAL) {
        throw FileSystemUnmountException("No file system mounted at given mount point.");
    }

    // When not supported by underlying file system driver.
    if (ret == -ENOTSUP) {
        throw FileSystemUnmountException("Not supported by underlying file system driver.");
    }

    // Any other unspecific error.
    throw FileSystemUnmountException("Unknown error.");
}