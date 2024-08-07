#include "common.h"
#include "smart_allocator.h"

#define SIZE 100

void heap_info() {
  std::stringstream ss;
  ss << heap.get_addr();
  uintptr_t decimal_var = 0;
  ss >> std::hex >> decimal_var;
  std::cout << std::endl;
  std::cout << "initial address from the heap : " << heap.get_addr() << " -- "
            << decimal_var << std::endl;

  std::cout << "max size of the heap : " << heap.get_max() << std::endl;
  std::cout << "actual size of the heap : " << heap.get_actual_size()
            << std::endl;

  std::cout << "contains free memory : "
            << (heap.get_contains_free_memory() ? "true" : "false")
            << std::endl;

  std::cout << "highest free memory : " << heap.get_highest_free_memory()
            << std::endl;
  std::cout << std::endl;
}

void test_alloc_in_free() {
  heap_info();

  smart_allocator<int> int_ptr(sizeof(int) * SIZE);
  smart_allocator<char> char_ptr(sizeof(char) * SIZE);
  if (smart_allocator<int> char_ptr2(sizeof(int) * SIZE); char_ptr2.get_ptr()) {
    for (int i = 0; i < SIZE * 2; i++) {
      char_ptr2.get_ptr()[i] = rand();
    }
  }
  smart_allocator<char> char_ptr2(sizeof(int) * SIZE - 42);
  heap.get_head()->print_node();

  heap_info();
}

void test_auto_free() {
  if (smart_allocator<int> ptr(sizeof(int) * SIZE); ptr.get_ptr()) {
    for (int i = 0; i < SIZE; i++) {
      ptr.get_ptr()[i] = rand();
    }

    std::cout << ptr.get_ptr()[11] << std::endl;
  }

  smart_allocator<char> ptr(sizeof(char) * SIZE);
  heap.get_head()->print_node();
}

void allocate_same_size_free() {
  heap_info();

  if (smart_allocator<int> ptr(sizeof(int) * SIZE); ptr.get_ptr()) {
    for (int i = 0; i < SIZE; i++) {
      ptr.get_ptr()[i] = rand();
    }

    std::cout << ptr.get_ptr()[11] << std::endl;
  }

  smart_allocator<int> ptr(sizeof(int) * SIZE);

  heap.get_head()->print_node();
  heap_info();
}

void test_merge_free() {
  heap_info();

  smart_allocator<int> ptr(sizeof(int) * SIZE);

  if (smart_allocator<int> ptr_temp(sizeof(int) * SIZE); ptr.get_ptr()) {
    for (int i = 0; i < SIZE; i++) {
      ptr.get_ptr()[i] = rand();
    }
  }

  if (smart_allocator<int> ptr_temp(sizeof(int) * SIZE + 2); ptr.get_ptr()) {
    for (int i = 0; i < SIZE; i++) {
      ptr.get_ptr()[i] = rand();
    }
  }

  if (smart_allocator<int> ptr_temp(sizeof(int) * SIZE + 4); ptr.get_ptr()) {
    for (int i = 0; i < SIZE; i++) {
      ptr.get_ptr()[i] = rand();
    }
  }

  heap.get_head()->print_node();
  heap_info();
}

int main() {
  test_merge_free();

  return 0;
}
