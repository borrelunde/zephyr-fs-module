#include <fs-module/IOException.hpp>

IOException::IOException(const char *what)
    : std::runtime_error(what) {
}