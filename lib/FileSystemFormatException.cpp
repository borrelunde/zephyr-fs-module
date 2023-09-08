#include <fs-module/FileSystemFormatException.hpp>

FileSystemFormatException::FileSystemFormatException(const char *what)
    : FileSystemException(what) {
}