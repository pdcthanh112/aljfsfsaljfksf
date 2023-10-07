#include <iostream>

#include "circularLinkedList.hpp"
#include "doubleLinkedList.hpp"
#include "singleLinkedList.hpp"

void handleLinkedList() {
  int choice;
  do {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                                   LINKED LIST                                             ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Single Linked List                                                                ||" << std::endl;
    std::cout << "||                      2. Double Linked List                                                                ||" << std::endl;
    std::cout << "||                      3. Circular Linked List                                                              ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;
    choice = getUserChoice(1, 3, 0);

    switch (choice) {
      case 1:
        singleLinkedList::handleSingleLinkedList();
        break;
        //   case 2:
        //     interchangeSort(arr, length);
        //     break;
        //   case 3:
        //     bubbleSort(arr, length);
        //     break;
      default:
        break;
    }
  } while (choice != 0);
}