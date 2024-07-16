#include "common.h"
#include "smart_allocator.h"

#define SIZE 100
int main() {
  smart_allocator<int> ptr(new int[SIZE]);
  ptr.get_ptr()[10] = 10;
  std::cout << ptr.get_ptr()[10] << std::endl;
}
