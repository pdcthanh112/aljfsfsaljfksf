#include <iostream>

#include "stackUsingArray.hpp"
#include "stackUsingLinkedList.hpp"

void handleStack() {
  
  int choice;
  do {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                                      STACK                                                ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Stack (using array)                                                               ||" << std::endl;
    std::cout << "||                      2. Stack (using linked-list)                                                         ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;
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
