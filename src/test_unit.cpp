#include "common.h"
#include "smart_allocator.h"

int main() {
  std::cout << "hello" << std::endl;
  smart_allocator<int *> ptr;
}
