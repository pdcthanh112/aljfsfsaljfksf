#include <iostream>

#include "algorithms/recursive.hpp"
#include "algorithms/search.hpp"
#include "algorithms/shortestPath.hpp"
#include "algorithms/sort.hpp"
#include "algorithms/stringSearching.hpp"
#include "data-structure/graph.hpp"
#include "data-structure/queue/main.hpp"
#include "data-structure/stack/main.hpp"
#include "data-structure/linked-list/main.hpp"
#include "data-structure/tree/main.hpp"
#include "design-pattern/main.hpp"
#include "oop/main.hpp"
#include "utils.hpp"

void handleDataStructure() {
  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                   DATA STRUCTURES                                         ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Array                                                                             ||\n";
    std::cout << "||                      2. Linked List                                                                       ||\n";
    std::cout << "||                      3. Stack                                                                             ||\n";
    std::cout << "||                      4. Queue                                                                             ||\n";
    std::cout << "||                      5. Tree                                                                              ||\n";
    std::cout << "||                      6. Graph                                                                             ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 6, 0);

    system("cls");
    switch (choice) {
      // case 1:
      //   quickSort(arr, 0, length)
      //   break;
      case 2:
        handleLinkedList();
        break;
      case 3:
        handleStack();
        break;
      case 4:
        handleQueue();
        break;
      case 5:
        handleTree();
        break;
      default:
        break;
    }
  } while (choice != 0);
}

void handleAlgorithm() {
  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                    ALGORITHM                                              ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Search                                                                            ||\n";
    std::cout << "||                      2. Sort                                                                              ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 2, 0);
    system("cls");
    switch (choice) {
      case 1:
        handleSearch();
        break;
      case 2:
        handleSort();
        break;
      default:
        break;
    }
  } while (choice != 0);
}

int main() {
  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                          -- DATA STRUCTURES & AGLORITHMS --                               ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Data structure                                                                    ||\n";
    std::cout << "||                      2. Algorithm                                                                         ||\n";
    std::cout << "||                      3. Design pattern                                                                    ||\n";
    std::cout << "||                      4. Object Oriented Programming (OOP)                                                 ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 4, 0);
    system("cls");

    switch (choice) {
      case 1:
        handleDataStructure();
        break;
      case 2:
        handleAlgorithm();
        break;
      case 3:
        handleDesignPattern();
        break;
      default:
        break;
    }
  } while (choice != 0);
}
