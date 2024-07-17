#include "heap.h"

// Initialization of the heap
heap_container heap;

void *heap_container::heap_alloc(size_t size) {
  // TODO add checking free memory

  void *addr = get_new_address();
  add_heap_size(size);

  return addr;
}
