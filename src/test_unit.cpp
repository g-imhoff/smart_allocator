#include "common.h"
#include "smart_allocator.h"

#define SIZE 100

void test_auto_free() {
  if (smart_allocator<int> ptr(sizeof(int) * SIZE); ptr.get_ptr()) {
    for (int i = 0; i < SIZE; i++) {
      ptr.get_ptr()[i] = rand();
    }

    std::cout << ptr.get_ptr()[11] << std::endl;
  }

  heap.get_head()->print_node();
}

int main() {
  test_auto_free();

  return 0;
}
