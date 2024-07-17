#pragma once

#include "common.h"

/**
 * Class used to manage the heap node as a double linked list
 * Each node is used to help us understand what is going on in the heap
 *
 * @brief This class is used to manage the heap node as a double linked list
 *
 * @param _size used to store the size of all the values stored in the addr
 * @param _addr used to store the address of the node
 * @param _free used to store if the node is free
 * @param _next used to store the next node
 * @param _previous used to store the previous node
 */

class heap_node {
private:
  std::size_t _size = 0;
  void *_addr = NULL;
  bool _free = false;

  heap_node *_next = NULL;
  heap_node *_previous = NULL;

public:
  /**
   * Constructor of the heap node
   *
   * @param size used to set the size of all the values stored in the addr
   * @param addr used to set the address of the node
   */
  heap_node(std::size_t size, void *addr) : _size(size), _addr(addr) {}

  /**
   * Used to get the size of the node
   *
   * @return return the size of the node
   */
  inline std::size_t get_size() { return _size; }
};
