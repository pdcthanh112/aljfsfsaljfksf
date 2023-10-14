#include <iostream>

namespace priorityQueue {
struct NODE {
  int data;
  int priority;
  NODE* pNext;
  NODE(int value) : data(value), pNext(nullptr) {}
};

}  // namespace priorityQueue