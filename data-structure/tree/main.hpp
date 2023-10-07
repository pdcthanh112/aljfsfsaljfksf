#include <iostream>

#include "./binarySearchTree.hpp"
using namespace std;

void handleTree() {
  int choice;
  do {
    cout << "===============================================================================================================" << endl;
    cout << "||                                                      TREE                                                 ||" << endl;
    cout << "||                              -------------------------------------------------------                      ||" << endl;
    cout << "||                      1. Tree                                                                              ||" << endl;
    cout << "||                      2. Binary search tree                                                                ||" << endl;
    cout << "||                      3. ALV tree                                                                          ||" << endl;
    cout << "||                      4. Red-Black tree                                                                    ||" << endl;
    cout << "||                      0. Exits                                                                             ||" << endl;
    cout << "===============================================================================================================" << endl;

    choice = getUserChoice(1, 4, 0);

    switch (choice) {
      // case 1:
      //   handleSearch();
      //   break;
      case 2:
        handleBinarySearchTree();
        break;
      default:
        break;
    }
  } while (choice != 0);
}