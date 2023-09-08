#pragma once

#include "FileSystemException.hpp"

class FileSystemMountException : public FileSystemException {
   public:
    FileSystemMountException(const char *what);
};