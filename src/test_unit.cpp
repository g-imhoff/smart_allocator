#include "common.h"
#include "smart_allocator.h"

int main() { 
  smart_allocator<int> ptr(5, sizeof(int));
  std::cout << ptr.get_value() << std::endl;
}
