#pragma once

#include "common.h"

#define HEAP_MAX_SIZE 64000000

class heap {
private:
  static void *addr;

  size_t max = HEAP_MAX_SIZE;
  size_t actual_size = 0;

  bool contains_free_memory = false;
  size_t highest_free_memory = SIZE_MAX;
};
