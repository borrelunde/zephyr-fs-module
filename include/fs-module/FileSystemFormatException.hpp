#pragma once

#include "FileSystemException.hpp"

class FileSystemFormatException : public FileSystemException {
   public:
    FileSystemFormatException(const char *what);
};