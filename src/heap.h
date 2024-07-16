#pragma once

#include "common.h"
#include "heap_node.h"

#define HEAP_MAX_SIZE 64000000
#define SEP_BYTES 1

class heap_container {
private:
  void *_heap_addr = mmap(NULL, HEAP_MAX_SIZE, PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  std::size_t _max = HEAP_MAX_SIZE;
  std::size_t _actual_size = 0; 

  bool _contains_free_memory = false;
  std::size_t _highest_free_memory = SIZE_MAX;

  heap_node *_head = NULL;

public:
  void *heap_alloc(std::size_t size);
  void heap_free(std::size_t size);
  inline void add_heap_size(std::size_t size) {
    _actual_size = _actual_size + size + SEP_BYTES;
  }
  inline void *get_new_address() { return _heap_addr + _actual_size; }
};

extern heap_container heap;
