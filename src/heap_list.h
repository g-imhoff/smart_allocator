#pragma once

#include "common.h"
#include "heap_node.h"

class heap_list {
  heap_node *actual = NULL;
  heap_node *next = NULL;
  heap_node *previous = NULL;
};
