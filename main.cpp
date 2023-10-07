#include "data-structure/tree/main.hpp"

#include <conio.h>

#include <iostream>

#include "algorithms/recursive.hpp"
#include "algorithms/search.hpp"
#include "algorithms/shortestPath.hpp"
#include "algorithms/sort.hpp"
#include "algorithms/stringSearching.hpp"
#include "data-structure/graph.hpp"
#include "data-structure/linked-list/main.hpp"
#include "data-structure/queue/main.hpp"
#include "data-structure/stack/main.hpp"
#include "utils.hpp"

using namespace std;

void handleDataStructure() {
  int choice;
  do {
    cout << "===============================================================================================================" << endl;
    cout << "||                                                   DATA STRUCTURES                                         ||" << endl;
    cout << "||                              -------------------------------------------------------                      ||" << endl;
    cout << "||                      1. Array                                                                             ||" << endl;
    cout << "||                      2. Linked List                                                                       ||" << endl;
    cout << "||                      3. Stack                                                                             ||" << endl;
    cout << "||                      4. Queue                                                                             ||" << endl;
    cout << "||                      5. Tree                                                                              ||" << endl;
    cout << "||                      6. Graph                                                                             ||" << endl;
    cout << "||                      0. Exits                                                                             ||" << endl;
    cout << "===============================================================================================================" << endl;
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
    // system('cls');
  int choice;
  do {
    cout << "===============================================================================================================" << endl;
    cout << "||                                                    ALGORITHM                                              ||" << endl;
    cout << "||                              -------------------------------------------------------                      ||" << endl;
    cout << "||                      1. Search                                                                            ||" << endl;
    cout << "||                      2. Sort                                                                              ||" << endl;
    cout << "||                      0. Exits                                                                             ||" << endl;
    cout << "===============================================================================================================" << endl;
    choice = getUserChoice(1, 2, 0);
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
    cout << "===============================================================================================================" << endl;
    cout << "||                                          -- DATA STRUCTURES & AGLORITHMS --                               ||" << endl;
    cout << "||                              -------------------------------------------------------                      ||" << endl;
    cout << "||                      1. Data structure                                                                    ||" << endl;
    cout << "||                      2. Algorithm                                                                         ||" << endl;
    cout << "||                      3. Design pattern                                                                    ||" << endl;
    cout << "||                      0. Exits                                                                             ||" << endl;
    cout << "===============================================================================================================" << endl;
    choice = getUserChoice(1, 2, 0);

    system("cls");
    switch (choice) {
      case 1:
        handleDataStructure();
        break;
      case 2:
        handleAlgorithm();
        break;
      case 0:
        exit(0);
      default:
        break;
    }
  } while (choice != 0);
}
