#include "heap_node.h"
#include "common.h"
#include "heap.h"

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
    node->_next = NULL;
  } else {
    std::cerr << "Error: node is NULL" << std::endl;
    throw std::runtime_error("Error: node is NULL");
  }
}

void heap_node::print_node() {
  heap_node *tmp = this;
  int i = 0;
  uintptr_t decimal_var = 0;
  std::stringstream ss;

  std::cout << "----------------------------------" << std::endl;
  while (tmp) {
    ss << tmp->_addr;
    ss >> std::hex >> decimal_var;
    std::cout << "Node: " << i << std::endl;
    std::cout << "The node size is : " << HEAP_NODE_SIZE << std::endl;
    std::cout << "Size: " << tmp->_size <<  std::endl;
    std::cout << "Addr: " << tmp->_addr << " -- " << decimal_var << std::endl;
    std::cout << "Free: " << (tmp->_free == true ? "true" : "false")
              << std::endl;

    if (tmp->_next) {
      std::cout << "####################" << std::endl;
    }

    tmp = tmp->_next;
    i++;
    ss.clear();
  }
  std::cout << "----------------------------------" << std::endl;
}

void *heap_node::find_lowest_higher_free(std::size_t size) {
  heap_node *tmp = this;
  void *addr = NULL;
  std::size_t actual_lowest = SIZE_MAX;

  while (tmp) {
    if (tmp->_free && tmp->_size > size + HEAP_NODE_SIZE &&
        tmp->_size < actual_lowest) {
      actual_lowest = tmp->_size;
      addr = tmp->_addr;
    }

    tmp = tmp->_next;
  }

  return addr;
}

heap_node *heap_node::get_node(void *addr) {
  heap_node *tmp = this;

  while (tmp) {
    if (tmp->_addr == addr) {
      return tmp;
    }

    tmp = tmp->_next;
  }

  return NULL;
}

void heap_node::set_free(bool eval) {
  _free = eval;

  if (eval == false) {
    heap.check_if_still_contains_free_memory();
  }
}

void *heap_node::split_node(std::size_t size) {
  _size -= size + HEAP_NODE_SIZE;

  void *addr_node = _addr + _size;
  heap_node *node = static_cast<heap_node *>(addr_node);
  void *addr_memory = addr_node + HEAP_NODE_SIZE;
  node->init_node(addr_memory, size);

  heap_node *next = _next;
  _next = node;
  node->_next = next;
  node->_previous = this;

  return addr_memory;
}
