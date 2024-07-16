#pragma once

#include "common.h"
#include "heap_list.h"

#define HEAP_MAX_SIZE 64000000
#define SEP_BYTES 1

class heap {
private:
  void *addr = mmap(NULL, HEAP_MAX_SIZE, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  size_t max = HEAP_MAX_SIZE;
  size_t actual_size = 0;

  bool contains_free_memory = false;
  size_t highest_free_memory = SIZE_MAX;

  heap_list node;

public:
  void heap_alloc(size_t size);
  void heap_free(size_t size);
  inline void add_size(size_t size) {
    actual_size = actual_size + size + SEP_BYTES;
  }
};
