#include "common.h"
#include "heap_node.h"
#include "smart_allocator.h"

#define SIZE 100
int main() {
  smart_allocator<int> ptr(new int[SIZE]);
  ptr.get_ptr()[10] = 10;
  std::cout << ptr.get_ptr()[10] << std::endl;

  heap_node node(sizeof(int), NULL);
  std::cout << sizeof(heap_node) << std::endl;
}
