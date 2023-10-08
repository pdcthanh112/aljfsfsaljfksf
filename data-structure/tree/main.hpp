#include <iostream>

#include "binarySearchTree.hpp"

void handleTree() {
  int choice;
  do {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                                      TREE                                                 ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Tree                                                                              ||" << std::endl;
    std::cout << "||                      2. Binary search tree                                                                ||" << std::endl;
    std::cout << "||                      3. ALV tree                                                                          ||" << std::endl;
    std::cout << "||                      4. Red-Black tree                                                                    ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;
    choice = getUserChoice(1, 4, 0);
    system("cls");

    switch (choice) {
      // case 1:
      //   handleSearch();
      //   break;
      case 2:
        binarySearchTree::handleBinarySearchTree();
        break;
      default:
        break;
    }
  } while (choice != 0);
}