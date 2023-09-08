#pragma once

#include <stdexcept>

class IOException : public std::runtime_error {
   public:
    IOException(const char *what);
};