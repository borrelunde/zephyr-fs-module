#pragma once

#include "FileSystemException.hpp"

class FileSystemUnmountException : public FileSystemException {
   public:
    FileSystemUnmountException(const char *what);
};