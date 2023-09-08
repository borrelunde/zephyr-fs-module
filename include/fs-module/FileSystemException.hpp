#pragma once

#include "IOException.hpp"

class FileSystemException : public IOException {
   public:
    FileSystemException(const char *what);
};