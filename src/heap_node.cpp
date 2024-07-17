#include "heap_node.h"

void heap_node::init_node(void *addr, std::size_t size) {
  _addr = addr;
  _size = size;
}

void heap_node::push_back(heap_node *node) {
  if (node != NULL) {
    heap_node *tmp = this;

    while (tmp->_next != NULL) {
      tmp = tmp->_next;
    }

    tmp->_next = node;
    node->_previous = tmp;
  } else {
    std::cerr << "Error: node is NULL" << std::endl;
    throw std::runtime_error("Error: node is NULL");
  }
}

void heap_node::print_node() {
  heap_node *tmp = this;

  while (tmp) {
    std::cout << "Node: " << tmp << std::endl;
    std::cout << "Size: " << tmp->_size << std::endl;
    std::cout << "Addr: " << tmp->_addr << std::endl;
    std::cout << "Free: " << tmp->_free << std::endl;

    tmp = tmp->_next;
  }
}
