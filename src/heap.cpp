#include "heap.h"

// Initialization of the heap
heap_container heap;

void *heap_container::heap_alloc(size_t size) {
  void *addr = NULL;
  if (heap.get_contains_free_memory() &&
      (addr = heap._head->got_exactly_size_free(size))) {
    return addr;
  } else if (heap.get_contains_free_memory() &&
             (addr = heap._head->find_lowest_higher_free(size))) {

    if (heap_node *node = heap._head->get_node(addr)) {
      addr = node->split_node(size);
    } else {
      std::cerr << "Error: address not found" << std::endl;
      throw std::runtime_error("Error: address not found");
    }

    return addr;
  }

  // Create the node
  heap_node *node = static_cast<heap_node *>(get_new_address());
  add_heap_size(HEAP_NODE_SIZE);

  // Get the address needed
  addr = get_new_address();
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

  if (tmp == NULL) {
    std::cerr << "Error: address not found" << std::endl;
    throw std::runtime_error("Error: address not found");
  }

  while (tmp) {
    if (tmp->get_addr() == addr) {
      tmp->set_free(true);
      break;
    }

    tmp = tmp->get_next();
  }

  if (tmp == NULL) {
    std::cerr << "Error: address not found" << std::endl;
    throw std::runtime_error("Error: address not found");
  }

  if (tmp->get_prev() && tmp->get_prev()->get_free()) {
    heap_node *prev = tmp->get_prev();
    prev->merge_next();
  } else if (tmp->get_next() && tmp->get_next()->get_free()) {
    tmp->merge_next();
  }

  heap.set_contains_free_memory(true);

  if (heap.get_highest_free_memory() < tmp->get_size()) {
    heap.set_highest_free_memory(tmp->get_size());
  }
}

void heap_container::check_if_still_contains_free_memory() {
  heap_node *tmp = _head;

  while (tmp) {
    if (tmp->get_free()) {
      return;
    }

    tmp = tmp->get_next();
  }

  heap.set_contains_free_memory(false);
  heap.set_highest_free_memory(0);
}
