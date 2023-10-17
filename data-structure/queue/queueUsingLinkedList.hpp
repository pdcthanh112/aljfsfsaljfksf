#include <iostream>

namespace queueUsingLinkedList {
struct NODE {
  int data;
  NODE* pNext;
  NODE(int value) : data(value), pNext(nullptr) {}
};

struct Queue {
  NODE* pHead;
  NODE* pTail;
  Queue() : pHead(nullptr), pTail(nullptr) {}
};

void enqueue(Queue*& queue, int value) {
  NODE* tmp = new NODE(value);

  if (queue->pTail == NULL) {
    queue->pHead = queue->pTail = tmp;
  }
  queue->pTail->pNext = tmp;
  queue->pTail = tmp;
}

NODE* dequeue(Queue*& queue) {
  if (queue->pHead == NULL) {
    std::cout << "Queue empty!!";
    return NULL;
  }
  NODE* tmp = queue->pHead;
  queue->pHead = queue->pHead->pNext;
  return tmp;
}

NODE* front(Queue*& queue) {
  return queue->pHead;
}

NODE* rear(Queue*& queue) {
  return queue->pTail;
}

void traverseQueue(Queue*& queue) {
  NODE* tmp = queue->pHead;
  while (tmp != NULL) {
    std::cout << tmp->data << ' ';
    tmp = tmp->pNext;
  }
  std::cout << std::endl;
}

void handleQueueUsingLinkedList() {
  int choice;
  Queue* queue = new Queue();
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                              QUEUE USING LINKED-LIST                                      ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Enqueue                                                                           ||\n";
    std::cout << "||                      2. Dequeue                                                                           ||\n";
    std::cout << "||                      3. Front                                                                             ||\n";
    std::cout << "||                      4. Rear                                                                              ||\n";
    std::cout << "||                      5. Traverse queue                                                                    ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 5, 0);

    switch (choice) {
      case 1: {
        int value;
        std::cout << "Input value: ";
        std::cin >> value;
        enqueue(queue, value);
        break;
      }
      case 2: {
        NODE* tmp = dequeue(queue);
        std::cout << "Element: " << tmp->data << std::endl;
        break;
      }
      case 3: {
        NODE* tmp = front(queue);
        std::cout << "Element at front: " << tmp->data << std::endl;
        break;
      }
      case 4: {
        NODE* tmp = rear(queue);
        std::cout << "Element at rear: " << tmp->data << std::endl;
        break;
      }
      case 5:
        traverseQueue(queue);
        break;
      default:
        break;
    }
  } while (choice != 0);
}

}  // namespace queueUsingLinkedList