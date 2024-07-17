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
  heap_node(std::size_t size, void *addr)
      : _size(size + SEP_BYTES), _addr(addr) {}

  /**
   * Used to get the size of the node
   *
   * @return return the size of the node
   */
  inline std::size_t get_size() { return _size; }

  /**
   * Initialization of the node
   *
   * @param addr where the content is set
   * @param size of the content
   */
  void init_node(void *addr, std::size_t size);

  /**
   * Used to push a node to the end of the list
   *
   * @param node the node to push at the end of the list
   */
  void push_back(heap_node *node);

  /**
   * Used to print the whole list of nodes
   */
  void print_node();

  /**
   * Get the address of the node
   *
   * @return return the address of the node
   */
  inline void *get_addr() { return _addr; }

  /**
   * Used to set the free value of the node
   *
   * @param eval the value to set
   */
  void set_free(bool eval);
  inline bool get_free() { return _free; }
  /**
   * Used to get the next value of this node
   *
   * @return return the next value of this node
   */
  inline heap_node *get_next() { return _next; }

  void *find_lowest_higher_free(std::size_t size);
  heap_node *get_node(void *addr);
  void *split_node(std::size_t size);
};
