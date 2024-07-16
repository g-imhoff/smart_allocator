#include "heap.h"

void *heap::addr = mmap(NULL, HEAP_MAX_SIZE, PROT_READ | PROT_WRITE,
                                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
