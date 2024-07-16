#pragma once

#include "common.h"
#include "heap.h"

template <typename T> class smart_allocator {
private:
  T *ptr;

public:
  smart_allocator(size_t size);
  ~smart_allocator();
  inline T *get() { return ptr; };
};
