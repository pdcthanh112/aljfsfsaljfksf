#include <iostream>

#include "../../utils.hpp"

namespace singleLinkedList {
struct NODE {
  int data;
  NODE* pNext;
  NODE(int value) : data(value), pNext(nullptr) {}
};
struct LinkedList {
  NODE* pHead;
  NODE* pTail;
  LinkedList() : pHead(nullptr), pTail(nullptr) {}
};

int getSize(NODE*& node) {
  int size = 0;
  NODE* tmp = node;
  while (tmp != NULL) {
    size++;
    tmp = tmp->pNext;
  }
  return size;
}

void traverseLinkedList(NODE*& node) {
  NODE* tmp = node;
  while (tmp != NULL) {
    std::cout << tmp->data << ' ';
    tmp = tmp->pNext;
  }
  std::cout << std::endl;
}

int findElement(NODE*& node, int value) {
  return 0;
}

void insertFirst(NODE*& node, int value) {  // node là phần tử head
  std::cout << "RRRRRRRRRRRRRRRRR" << node;
  NODE* tmp = new NODE(value);
  if (node == NULL) {
    node = tmp;
  } else {
    tmp->pNext = node;
    node = tmp;
  }
}

void insertLast(NODE*& node, int value) {
  NODE* tmp = new NODE(value);
  if (node == NULL) {
    node = tmp;
  } else {
    NODE* a = node;
    while (a->pNext != NULL) {
      a = a->pNext;
    }
    a->pNext = tmp;
  }
}

void insertAtPosition(NODE*& node, int value, int position) {
  int size = getSize(node);
  if (position < 0 || position > size) {
    std::cout << "Position invalid!!\n";
  } else if (position == 0) {
    insertFirst(node, value);
  } else if (position == size - 1) {
    insertLast(node, value);
  } else {
    NODE* p = node;
    for (int i = 0; i < position - 1; i++) {
      p = p->pNext;
    }
    NODE* tmp = new NODE(value);
    tmp->pNext = p->pNext;
    p->pNext = tmp;
  }
}

void deleteFirst(NODE*& node) {
  if (node == NULL) return;
  node = node->pNext;
}

void deleteLast(NODE*& node) {
  if (node == NULL) return;
  NODE *prev = nullptr, *next = node;
  while (next->pNext != NULL) {
    prev = next;
    next = next->pNext;
  }
  if (prev == NULL) {
    node = NULL;
  } else {
    prev->pNext = nullptr;
  }
}

void deleteAtPosition(NODE*& node, int position) {
  int size = getSize(node);
  if (position < 0 || position > size - 1) {
    std::cout << "Position invalid!!\n";
  } else if (position == 0) {
    deleteFirst(node);
  } else if (position == size) {
    deleteLast(node);
  } else {
    NODE *prev = nullptr, *next = node;
    for (int i = 0; i < position; i++) {
      prev = next;
      next = next->pNext;
    }
    if (prev == NULL) {
      node = node->pNext;
    } else {
      prev->pNext = next->pNext;
    }
  }
}

void reverseLinkedList(NODE*& node) {
  NODE* current = node;
  NODE* prev = NULL;
  NODE* next = NULL;
  while (current != NULL) {
    next = current->pNext;
    current->pNext = prev;
    prev = current;
    current = next;
  }
  node = prev;
}

void handleSingleLinkedList() {
  int choice;
  NODE* head = nullptr;
  do {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                                 SINGLE LINKED-LIST                                        ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Insert element at head                                                            ||" << std::endl;
    std::cout << "||                      2. Insert element at tail                                                            ||" << std::endl;
    std::cout << "||                      3. Insert element at position                                                        ||" << std::endl;
    std::cout << "||                      4. Delete element at head                                                            ||" << std::endl;
    std::cout << "||                      5. Delete element at tail                                                            ||" << std::endl;
    std::cout << "||                      6. Delete element at position                                                        ||" << std::endl;
    std::cout << "||                      7. Traverse linked list                                                              ||" << std::endl;
    std::cout << "||                      8. Find element                                                                      ||" << std::endl;
    std::cout << "||                      9. Reverse linked list                                                               ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;
    choice = getUserChoice(1, 9, 0);

    switch (choice) {
      case 1: {
        int value;
        std::cout << "Input value: ";
        std::cin >> value;
        insertFirst(head, value);
        break;
      }
      case 2: {
        int value;
        std::cout << "Input value: ";
        std::cin >> value;
        insertLast(head, value);
        break;
      }
      case 3: {
        int value, position;
        std::cout << "Input value: ";
        std::cin >> value;
        std::cout << "Input position: ";
        std::cin >> position;
        insertAtPosition(head, value, position);
        break;
      }
      case 4:
        deleteFirst(head);
        break;
      case 5:
        deleteLast(head);
        break;
      case 6:
        int position;
        std::cout << "Input position: ";
        std::cin >> position;
        deleteAtPosition(head, position);
        break;
      case 7:
        traverseLinkedList(head);
        break;
      case 8: {
        int target;
        std::cout << "Input value you want to find: ";
        std::cin >> target;
        findElement(head, target);
        break;
      }
      case 9:
        reverseLinkedList(head);
        break;
      default:
        break;
    }
  } while (choice != 0);
}

}  // namespace singleLinkedList
