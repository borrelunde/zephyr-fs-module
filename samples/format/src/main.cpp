#include <zephyr/drivers/flash.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

#include <fs-lib/FileSystem.hpp>
#include <fs-lib/FileSystemFormatException.hpp>

#define LIBRARY_NAME "Zephyr File System Module"
#define SAMPLE_PATH "samples\\format"

int main() {
    LOG_INF("%s | %s: begun", LIBRARY_NAME, SAMPLE_PATH);

    // Instance of file system.
    std::unique_ptr<FileSystem> file_system = std::make_unique<FatFileSystem>();

    // Format file system volume.
    try {
        file_system->format();
        LOG_INF("%s", "Format file system volume.");
    } catch (const FileSystemFormatException &e) {
        LOG_ERR("Failed to format file system volume: %s", e.what());
    }

    LOG_INF("%s | %s: ended", LIBRARY_NAME, SAMPLE_PATH);
    return 0;
}