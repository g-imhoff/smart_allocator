#include "heap.h"

// Initialization of the heap
heap_container heap;

void *heap_container::heap_alloc(size_t size) {
  // TODO: add checking free memory

  // Create the node
  heap_node *node = static_cast<heap_node *>(get_new_address());
  add_heap_size(sizeof(heap_node));

  // Get the address needed
  void *addr = get_new_address();
  add_heap_size(size);

  node->init_node(addr, size);

  if (_head == NULL) {
    _head = node;
  } else {
    _head->push_back(node);
  }

  return addr;
}

void heap_container::heap_free(void *addr) {
  heap_node *tmp = _head;

  while (tmp) {
    if (tmp->get_addr() == addr) {
      tmp->set_free(true);
      break;
    }

    tmp = tmp->get_next();
  }
}
