#include "common.h"
#include "smart_allocator.h"

#define SIZE 100

void test_alloc_in_free() {
  smart_allocator<int> int_ptr(sizeof(int) * SIZE);
  smart_allocator<char> char_ptr(sizeof(char) * SIZE);
  if (smart_allocator<int> char_ptr2(sizeof(int) * SIZE * 2);
      char_ptr2.get_ptr()) {
    for (int i = 0; i < SIZE * 2; i++) {
      char_ptr2.get_ptr()[i] = rand();
    }

    std::cout << char_ptr2.get_ptr()[11] << std::endl;
  }
  smart_allocator<char> char_ptr3(sizeof(char) * SIZE);
  heap.get_head()->print_node();
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

int main() {
  test_alloc_in_free();

  return 0;
}
