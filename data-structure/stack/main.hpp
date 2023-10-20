#include <iostream>

#include "stackUsingArray.hpp"
#include "stackUsingLinkedList.hpp"

void handleStack() {
  
  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                      STACK                                                ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Stack (using array)                                                               ||\n";
    std::cout << "||                      2. Stack (using linked-list)                                                         ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 2, 0);
    system("cls");
    switch (choice) {
      // case 1:
      //   stackUsingLinkedList::handleStackUsingLinkedList();
      //   break;
      case 2:
        stackUsingLinkedList::handleStackUsingLinkedList();
        break;
      default:
        break;
    }
  } while (choice != 0);
}
