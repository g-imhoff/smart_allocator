#pragma once

#include "common.h"
#include "heap.h"

template <typename T> class smart_allocator {
private:
  T *_ptr;

public:
  smart_allocator(std::size_t size) { _ptr = (T *)heap.heap_alloc(size); };
  smart_allocator(void *ptr) { _ptr = (T *)ptr; };
  ~smart_allocator(){};
  inline T *get_ptr() const { return _ptr; };

  void *operator new(std::size_t size) { return heap.heap_alloc(size); };
};
