#pragma once

#include "common.h"

class heap_node {
private:
  std::size_t _size = 0;
  void *_addr = NULL;
  bool _free = false;

  heap_node *_next = NULL;
  heap_node *_previous = NULL;

public:
  heap_node(std::size_t size, void *addr) : _size(size), _addr(addr){};
  inline std::size_t get_size() { return _size; }
};
