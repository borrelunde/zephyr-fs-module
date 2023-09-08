#pragma once

#include <memory>
#include <string>

/**
 * @brief Interface all file systems should implement from.
 */
struct FileSystem {
    /**
     * @brief Destroys the File System object.
     */
    virtual ~FileSystem() = default;

    /**
     * @brief Format file system.
     *
     * Deletes all data on the volume.
	 * 
	 * @throw FileSystemFormatException if formatting failed for any reason.
     */
    virtual void format() = 0;

    /**
     * @brief Mount file system on the mount point.
     *
     * @param mount_point name of the mount point. For example "/SD:".
	 * 
	 * @throw FileSystemMountException if mounting failed for any reason.
     */
    virtual void mount(const std::string &mount_point) = 0;

    /**
     * @brief Unmount file system.
	 * 
	 * @throw FileSystemUnmountException if unmounting failed for any reason.
     */
    virtual void unmount() = 0;
};