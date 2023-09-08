#include <zephyr/drivers/flash.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

#include <fs-lib/FileSystem.hpp>
#include <fs-lib/FileSystemMountException.hpp>

#define LIBRARY_NAME "Zephyr File System Module"
#define SAMPLE_PATH "samples\\mount"

const std::string FS_MNTP = "/SD:";

int main() {
    LOG_INF("%s | %s: begun", LIBRARY_NAME, SAMPLE_PATH);

    // Instance of file system.
    std::unique_ptr<FileSystem> file_system = std::make_unique<FatFileSystem>();

    // Mount file system.
    try {
        file_system->mount(FS_MNTP);
        LOG_INF("%s", "Mounted file system.");
    } catch (const FileSystemMountException &e) {
        LOG_ERR("Failed to mount file system: %s", e.what());
    }

    LOG_INF("%s | %s: ended", LIBRARY_NAME, SAMPLE_PATH);
    return 0;
}