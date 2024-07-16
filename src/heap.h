#pragma once

#include "common.h"
#include "heap_list.h"

#define HEAP_MAX_SIZE 64000000
#define SEP_BYTES 1

class heap_container {
private:
  void *heap_addr = mmap(NULL, HEAP_MAX_SIZE, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  std::size_t max = HEAP_MAX_SIZE;
  std::size_t actual_size = 0;

  bool contains_free_memory = false;
  std::size_t highest_free_memory = SIZE_MAX;

  heap_list node;

public:
  void *heap_alloc(std::size_t size);
  void heap_free(std::size_t size);
  inline void add_heap_size(std::size_t size) {
    actual_size = actual_size + size + SEP_BYTES;
  }
  inline void *get_new_address() { return heap_addr + actual_size; }
};

extern heap_container heap;
