#include <iostream>

#include "queueUsingLinkedList.hpp"
void handleQueue() {
  int choice;
  do {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                                      QUEUE                                                ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Queue (using array)                                                               ||" << std::endl;
    std::cout << "||                      2. Queue (using linked list)                                                         ||" << std::endl;
    std::cout << "||                      3. Priority Queue                                                                    ||" << std::endl;
    std::cout << "||                      4. Double Ended Queue                                                                ||" << std::endl;
    std::cout << "||                      5. Circular Queue                                                                    ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;
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
