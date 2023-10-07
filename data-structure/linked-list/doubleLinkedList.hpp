#include <iostream>

namespace doubleLinkedList {
struct NODE {
  int data;
  NODE* prev;
  NODE* next;
  NODE(int value) : data(value), prev(nullptr), next(nullptr) {}
};

}  // namespace doubleLinkedList