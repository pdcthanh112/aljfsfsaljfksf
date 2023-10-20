#include <iostream>

#include "utils.hpp"

class AbstractStorage {
 public:
  std::string name;
  virtual int getSize() = 0;
};

class File : public AbstractStorage {
 public:
  int getSize() {
    return 1;
  }
};

class Folder : public AbstractStorage {
 public:
  AbstractStorage** ChildList;
  int nChild;
  int getSize() {
    if (ChildList == NULL) return 0;
    int size = 0;
    for (int i = 0; i < nChild; i++)
      size = size + ChildList[i]->getSize();
    return size;
  }
};

class Drive {
 public:
  std::string name;
  AbstractStorage** ChildList;
  int nChild;
  int getSize() {
    if (ChildList == NULL) return 0;
    int size = 0;
    for (int i = 0; i < nChild; i++)
      size = size + ChildList[i]->getSize();
    return size;
  }
};

int main() {
  Drive* drive = new Drive();

  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                DRIVE MANAGEMENT                                           ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Create folder                                                                     ||\n";
    std::cout << "||                      2. Create file                                                                       ||\n";
    std::cout << "||                      3. Red-Black tree                                                                    ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 4, 0);
    system("cls");

    switch (choice) {
      case 1: {
        std::string folderName;
        std::cout << "Input folder name: ";
        std::getline(std::cin, folderName);
        Folder* folder = new Folder();
        folder->name = folderName;
        
        break;
      }
      case 2: {
        std::string fileName;
        std::cout << "Input file name: ";
        std::getline(std::cin, fileName);
        File* file = new File();
        file->name = fileName;

        break;
      }
      default:
        break;
    }
  } while (choice != 0);
  return 0;
}