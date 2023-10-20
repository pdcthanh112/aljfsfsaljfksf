#include <iostream>

#include "binarySearchTree.hpp"

void handleTree() {
  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                      TREE                                                 ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Tree                                                                              ||\n";
    std::cout << "||                      2. Binary search tree                                                                ||\n";
    std::cout << "||                      3. ALV tree                                                                          ||\n";
    std::cout << "||                      4. Red-Black tree                                                                    ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
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