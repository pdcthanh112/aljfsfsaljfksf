#include <iostream>

namespace stackUsingLinkedList {
struct NODE {
  int data;
  NODE* pNext;
  NODE(int value) : data(value), pNext(nullptr) {}
};

struct Stack {
  NODE* pHead;
  NODE* pTail;
  Stack() : pHead(nullptr), pTail(nullptr) {}
};

void push(Stack*& stack, int value) {
  NODE* tmp = new NODE(value);
  if (stack->pHead == NULL) {
    stack->pHead = tmp;
  } else {
    tmp->pNext = stack->pHead;
    stack->pHead = tmp;
  }
}

NODE* pop(Stack*& stack) {
  if (stack == NULL || stack->pHead == NULL || stack->pTail == NULL) {
    std::cout << "Stack is empty!!";
    return NULL;
  } else {
    stack->pHead = stack->pHead->pNext;
    return stack->pHead;
  }
}

NODE* top(Stack*& stack) {
  return stack->pHead;
}

void traverseStack(Stack*& stack) {
  NODE* tmp = stack->pHead;
  while (tmp != NULL) {
    std::cout << tmp->data << ' ';
    tmp = tmp->pNext;
  }
  std::cout << std::endl;
}

void handleStackUsingLinkedList() {
  int choice;
  Stack* stack = new Stack();
  do {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                                      STACK                                                ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Push                                                                              ||" << std::endl;
    std::cout << "||                      2. Pop                                                                               ||" << std::endl;
    std::cout << "||                      3. Top                                                                               ||" << std::endl;
    std::cout << "||                      4. Traverse Stack                                                                    ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;
    choice = getUserChoice(1, 4, 0);

    switch (choice) {
      case 1: {
        int value;
        std::cout << "Input value: ";
        std::cin >> value;
        push(stack, value);
        break;
      }
      case 2: {
        NODE* tmp = pop(stack);
        std::cout << "Element: " << tmp->data << std::endl;
        break;
      }
      case 3: {
        NODE* tmp = top(stack);
        std::cout << "Element: " << tmp->data << std::endl;
        break;
      }
      case 4:
        traverseStack(stack);
        break;
      default:
        break;
    }
  } while (choice != 0);
}

}  // namespace stackUsingLinkedList
