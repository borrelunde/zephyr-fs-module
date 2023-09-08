#include <fs-module/FileSystemException.hpp>

FileSystemException::FileSystemException(const char *what)
    : IOException(what) {
}