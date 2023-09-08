#include <fs-module/FileSystemMountException.hpp>

FileSystemMountException::FileSystemMountException(const char *what)
    : FileSystemException(what) {
}