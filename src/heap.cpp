#include "heap.h"
#include <cstddef>

void heap::allocate_memory(size_t size) {
  // TODO add checking free memory

  ptrdiff_t address = dynamic_cast<ptrdiff_t>(addr) + actual_size;
  add_size(size);
}
