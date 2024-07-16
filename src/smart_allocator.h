#pragma once

#include "common.h"

template <typename T> class smart_allocator {
private:
  T *ptr;

public:
  smart_allocator() { std::cout << "hello" << std::endl; }
};
