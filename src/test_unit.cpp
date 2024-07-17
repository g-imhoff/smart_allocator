#include "common.h"
#include "heap_node.h"
#include "smart_allocator.h"

#define SIZE 100
int main() {
  smart_allocator<int> ptr(sizeof(int) * SIZE);

  for (int i = 0; i < SIZE; i++) {
    ptr.get_ptr()[i] = rand();
  }

  heap.get_head()->print_node();
}
