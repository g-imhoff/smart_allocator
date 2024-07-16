#pragma once

#include "common.h"

class heap_node {
private:
  std::size_t size = 0;
  void *addr = NULL;
  bool free = false;
};
