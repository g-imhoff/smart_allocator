#pragma once

#include "common.h"
#include "heap_node.h"

#define HEAP_MAX_SIZE 64000000

/**
 * Class used to manage the heap
 *
 * @brief This class is used to manage the heap
 *
 * @param _heap_addr used to store the address of the heap
 * @param _max used to store the max size of the heap
 * @param _actual_size used to store the actual size of the heap
 * @param _contains_free_memory used to store if the heap contains free memory
 * @param _highest_free_memory used to store the highest free memory
 * @param _head used to store a double linked list of heap nodes
 */

constexpr std::size_t HEAP_NODE_SIZE = sizeof(heap_node);

class heap_container {
private:
  void *_heap_addr = mmap(NULL, HEAP_MAX_SIZE, PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  std::size_t _max = HEAP_MAX_SIZE;
  std::size_t _actual_size = 0;

  bool _contains_free_memory = false;
  std::size_t _highest_free_memory = 0;

  heap_node *_head = NULL;

public:
  /**
   * Used to allocate some memory
   *
   * @param size used to set the size of memory allocated
   *
   * @return return the address where the memory is allocated
   */
  void *heap_alloc(std::size_t size);

  /**
   * Used to free some memory
   *
   * @param addr used to find the node to free
   */
  void heap_free(void *addr);

  /**
   * Used to add some size to heap
   *
   */
  inline void add_heap_size(std::size_t size) {
    _actual_size = _actual_size + size;
  }

  /**
   * Used to get an address that is available
   *
   * @return return the new address
   */
  inline void *get_new_address() { return _heap_addr + _actual_size; }

  /**
   * Used to get the head of the heap node
   *
   * @return return the head of the heap node
   */
  inline heap_node *get_head() { return _head; }

  /**
   * Used to get the maximum size free in the heap
   *
   * @return return the maximum size free in the heap
   */
  inline std::size_t get_highest_free_memory() { return _highest_free_memory; }

  /**
   * Used to know if there is free memory in the heap
   *
   * @return return the boolean if there is free memory in the heap
   */
  inline bool get_contains_free_memory() { return _contains_free_memory; }

  /**
   * Used to set the contains free memory
   *
   * @param contains_free_memory used to set the contains free memory
   */
  inline void set_contains_free_memory(bool contains_free_memory) {
    _contains_free_memory = contains_free_memory;
  }

  inline void set_highest_free_memory(std::size_t highest_free_memory) {
    _highest_free_memory = highest_free_memory;
  }

  inline void *get_addr() { return _heap_addr; }

  inline std::size_t get_max() { return _max; }
  inline std::size_t get_actual_size() { return _actual_size; }
  void check_if_still_contains_free_memory();
};

// Declaration of the heap
extern heap_container heap;
