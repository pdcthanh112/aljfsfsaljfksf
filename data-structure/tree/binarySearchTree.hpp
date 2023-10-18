#include <cmath>
#include <iostream>
#include <queue>

namespace binarySearchTree {

struct NODE {
  int data;
  NODE* pLeft;
  NODE* pRight;
  NODE(int value) : data(value), pLeft(nullptr), pRight(nullptr) {}
};

// dùng đệ quy
NODE* searchItem(NODE*& root, int target) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == target) {
    return root;
  } else {
    if (target < root->data) {
      return searchItem(root->pLeft, target);
    } else {
      return searchItem(root->pRight, target);
    }
  }
}

// // không dùng đệ quy
// NODE* searchItem(NODE*& root, int target) {
//   if (root == NULL) {
//     return NULL;
//   }
//   NODE* tmp = root;
//   while (tmp != NULL) {
//     if (tmp->data == target) {
//       return tmp;
//     } else {
//       if (target < tmp->data) {
//         tmp = tmp->pLeft;
//       } else {
//         tmp = tmp->pRight;
//       }
//     }
//   }
//   return NULL;
// }

void insertElement(NODE*& root, int value) {
  if (root == NULL || root->data == 0) {
    root = new NODE(value);
    return;
  }
  if (root->data == value) {
    std::cout << "Element " << value << "already exist in BST!!";
  } else {
    if (value < root->data) {
      insertElement(root->pLeft, value);
    } else {
      insertElement(root->pRight, value);
    }
  }
}

NODE* deleteElement(NODE* root, int value) {
  if (root == NULL) {
    std::cout << "Tree empty!!";
    return root;
  }

  if (value < root->data) {
    root->pLeft = deleteElement(root->pLeft, value);
    return root;
  } else if (value > root->data) {
    root->pRight = deleteElement(root->pRight, value);
    return root;
  }

  if (root->pLeft == NULL) {
    NODE* temp = root->pRight;
    delete root;
    return temp;
  } else if (root->pRight == NULL) {
    NODE* temp = root->pLeft;
    delete root;
    return temp;
  }else {
    NODE* succParent = root;

    NODE* succ = root->pRight;
    while (succ->pLeft != NULL) {
      succParent = succ;
      succ = succ->pLeft;
    }

    if (succParent != root) {
      succParent->pLeft = succ->pRight;
    } else {
      succParent->pRight = succ->pRight;
    }

    root->data = succ->data;

    delete succ;
    return root;
  }
}

int getHeight(NODE* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + std::max(getHeight(root->pLeft), getHeight(root->pRight));
}

void preorderTraversal(NODE*& root) {
  if (root != NULL) {
    std::cout << root->data << " ";
    preorderTraversal(root->pLeft);
    preorderTraversal(root->pRight);
  }
}

void inorderTraversal(NODE*& root) {
  if (root != NULL) {
    inorderTraversal(root->pLeft);
    std::cout << root->data << " ";
    inorderTraversal(root->pRight);
  }
}

void postorderTraversal(NODE*& root) {
  if (root != NULL) {
    postorderTraversal(root->pLeft);
    postorderTraversal(root->pRight);
    std::cout << root->data << " ";
  }
}

bool checkBST(NODE* node, int min, int max) {
  if (node == nullptr) {
    return true;
  }

  if (node->data < min || node->data > max) {
    return false;
  }

  return checkBST(node->pLeft, min, node->data - 1) && checkBST(node->pRight, node->data + 1, max);
}

void printBinaryTree(NODE*& root) {
  std::queue<NODE*> treeLevel, temp;
  treeLevel.push(root);
  int counter = 0;
  int height = getHeight(root) - 1;
  double numberOfElements = pow(2, (height + 1)) - 1;
  while (counter <= height) {
    NODE* removed = treeLevel.front();
    treeLevel.pop();
    if (temp.empty()) {
      double n = numberOfElements / pow(2, counter + 1);
      for (; n > 0; n--) {
        std::cout << "\t";
      }
      if (removed == nullptr) {
        std::cout << " ";
      } else {
        std::cout << removed->data;
      }
    } else {
      double n = numberOfElements / pow(2, counter);
      for (; n > 0; n--) {
        std::cout << "\t";
      }
      if (removed == nullptr) {
        std::cout << " ";
      } else {
        std::cout << removed->data;
      }
    }
    if (removed == nullptr) {
      temp.push(nullptr);
      temp.push(nullptr);
    } else {
      temp.push(removed->pLeft);
      temp.push(removed->pRight);
    }
    if (treeLevel.empty()) {
      std::cout << std::endl
                << std::endl;
      treeLevel = temp;
      while (!temp.empty()) {
        temp.pop();
      }
      counter++;
    }
  }
}

void handleBinarySearchTree() {
  NODE* bst = new NODE(NULL);
  insertElement(bst, 25);
  insertElement(bst, 15);
  insertElement(bst, 51);
  insertElement(bst, 10);
  insertElement(bst, 21);
  insertElement(bst, 35);
  insertElement(bst, 70);
  insertElement(bst, 4);
  insertElement(bst, 12);
  insertElement(bst, 18);
  insertElement(bst, 24);
  insertElement(bst, 31);
  insertElement(bst, 44);
  insertElement(bst, 66);
  insertElement(bst, 90);
  // insertElement(bst, 81);
  // insertElement(bst, 13);
  // insertElement(bst, 23);
  // insertElement(bst, 37);
  // insertElement(bst, 78);
  // insertElement(bst, 22);
  // insertElement(bst, 68);
  // insertElement(bst, 99);
  // insertElement(bst, 88);

  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                               BINARY SEARCH TREE                                          ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Insert element                                                                    ||\n";
    std::cout << "||                      2. Delete element                                                                    ||\n";
    std::cout << "||                      3. Search element                                                                    ||\n";
    std::cout << "||                      4. Get height                                                                        ||\n";
    std::cout << "||                      5. Preorder (NLR) Traversal                                                          ||\n";
    std::cout << "||                      6. Inorder (LNR) Traversal                                                           ||\n";
    std::cout << "||                      7. Postorder (LRN) Traversal                                                         ||\n";
    std::cout << "||                      8. Check BST                                                                         ||\n";
    std::cout << "||                      9. Print tree                                                                        ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";

    choice = getUserChoice(1, 9, 0);

    switch (choice) {
      case 1: {
        int value;
        std::cout << "Input value: ";
        std::cin >> value;
        insertElement(bst, value);
        break;
      }
      case 2: {
        int element;
        std::cout << "Input element you want to delete: ";
        std::cin >> element;
        deleteElement(bst, element);
        break;
      }
      case 3: {
        int target;
        std::cout << "Input number you want to find: ";
        std::cin >> target;
        NODE* result = searchItem(bst, target);
        return;
      }
      case 4:
        std::cout << "Height of tree: " << getHeight(bst) << std::endl;
        break;
      case 5:
        std::cout << "Pre-order traversal: ";
        preorderTraversal(bst);
        std::cout << std::endl;
        break;
      case 6:
        std::cout << "In-order traversal: ";
        inorderTraversal(bst);
        std::cout << std::endl;
        break;
      case 7:
        std::cout << "Post-order traversal: ";
        postorderTraversal(bst);
        std::cout << std::endl;
        break;
      case 8: {
        bool result = checkBST(bst, INT_MIN, INT_MAX);
        if (result) {
          std::cout << "TRUE";
        } else {
          std::cout << "FALSE";
        }
        break;
      }
      case 9:
        printBinaryTree(bst);
        break;
      default:
        break;
    }
  } while (choice != 0);
}

}  // namespace binarySearchTree