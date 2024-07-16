#pragma once

#include "common.h"
#include "heap.h"

template <typename T> class smart_allocator {
private:
  T *ptr;

public:
  smart_allocator(T value, std::size_t size) {
    ptr = (T *)heap.heap_alloc(size);
    *ptr = value;
  };
  ~smart_allocator(){};
  inline T *get_ptr() const { return ptr; };
  inline T get_value() const { return *ptr; };
};
