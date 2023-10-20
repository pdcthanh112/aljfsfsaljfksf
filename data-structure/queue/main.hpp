#include <iostream>

#include "queueUsingLinkedList.hpp"

void handleQueue() {
  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                      QUEUE                                                ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Queue (using array)                                                               ||\n";
    std::cout << "||                      2. Queue (using linked list)                                                         ||\n";
    std::cout << "||                      3. Priority Queue                                                                    ||\n";
    std::cout << "||                      4. Double Ended Queue                                                                ||\n";
    std::cout << "||                      5. Circular Queue                                                                    ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 5, 0);
    system("cls");
    switch (choice) {
        //   case 1: {
        //     int value;
        //     std::cout << "Input value: ";
        //     std::cin >> value;
        //     enqueue(queue, value);
        //     break;
        //   }
          case 2:
            queueUsingLinkedList::handleQueueUsingLinkedList();
            break;
        // case 3:
        //   bubbleSort(arr, length);
        //   break;
        // case 4:
        //   insertionSort(arr, length);
        //   break;
        //   case 5:
        //     handleTree();
        //     break;
      default:
        break;
    }
  } while (choice != 0);
}
