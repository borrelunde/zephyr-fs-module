#include <fs-module/FileSystemUnmountException.hpp>

FileSystemUnmountException::FileSystemUnmountException(const char *what)
    : FileSystemException(what) {
}