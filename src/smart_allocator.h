#pragma once

#include "common.h"
#include "heap.h"

/**
 * This smart allocator is a class that is used to allocate memory on the heap
 * and allow us to automatically free it
 *
 * @brief Smart allocator class
 *
 * @tparam T used for make smart_allocator for any type (basically a container)
 *
 * @param _ptr used to store the pointer to the memory allocated
 */
template <typename T> class smart_allocator {
private:
  T *_ptr;

public:
  /**
   * Constructor of the smart allocator
   *
   * @param size used to set the size of the memory allocated
   */
  smart_allocator(std::size_t size) { _ptr = (T *)heap.heap_alloc(size); };

  /**
   * Constructor of the smart allocator
   *
   * @param ptr used to set the pointer to the memory allocated
   */
  smart_allocator(void *ptr) : _ptr(static_cast<T *>(ptr)) {}

  /**
   * Destructor of the smart allocator
   */
  ~smart_allocator() {
    heap.heap_free(_ptr);
    _ptr = NULL;
  }

  /**
   * Used to get the pointer to the memory allocated
   *
   * @return return the pointer to the memory allocated
   */
  inline T *get_ptr() const { return _ptr; }
};
