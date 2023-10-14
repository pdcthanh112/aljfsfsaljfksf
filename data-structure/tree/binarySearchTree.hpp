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

NODE* searchItem(NODE*& node, int target) {
  if (node == NULL) {
    return NULL;
  }
  if (node->data == target) {
    return node;
  } else {
    if (target < node->data) {
      return searchItem(node->pLeft, target);
    } else {
      return searchItem(node->pRight, target);
    }
  }
}

void insertElement(NODE*& root, int value) {
  if (root == NULL || root->data == 0) {  //////////////// tại vì khởi tạo NULL thì tự nó chuyển qua 0 đéo biết fix
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

NODE* deleteItem(NODE*& root, int key) {
  // if (root == nullptr) {
  //   return nullptr;
  // }

  // if (key < root->value) {
  //   root->left = deleteItem(root->left, key);
  // } else if (key > root->value) {
  //   root->right = deleteItem(root->right, key);
  // } else {
  //   if (root->left == nullptr) {
  //     NODE* temp = root->right;
  //     delete root;
  //     return temp;
  //   } else if (root->right == nullptr) {
  //     NODE* temp = root->left;
  //     delete root;
  //     return temp;
  //   }

  //   NODE* temp = find(root->right);
  //   root->value = temp->value;
  //   root->right = deleteItem(root->right, temp->value);
  // }

  // return root;
}

int getHeight(NODE* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + std::max(getHeight(root->pLeft), getHeight(root->pRight));
}

void preorderTraversal(NODE*& node) {
  if (node != NULL) {
    std::cout << node->data << " ";
    preorderTraversal(node->pLeft);
    preorderTraversal(node->pRight);
  }
}

void inorderTraversal(NODE*& node) {
  if (node != NULL) {
    inorderTraversal(node->pLeft);
    std::cout << node->data << " ";
    inorderTraversal(node->pRight);
  }
}

void postorderTraversal(NODE*& node) {
  if (node != NULL) {
    postorderTraversal(node->pLeft);
    postorderTraversal(node->pRight);
    std::cout << node->data << " ";
  }
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
      std::cout << std::endl << std::endl;
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

  // NODE* bst = new NODE(1);
  // NODE* temp = nullptr;
  // temp = new NODE(2);
  // bst->pLeft = temp;
  // temp = new NODE(3);
  // bst->pRight = temp;

  // temp = new NODE(4);
  // bst->pLeft->pLeft = temp;
  // temp = new NODE(5);
  // bst->pLeft->pRight = temp;
  // temp = new NODE(6);
  // bst->pRight->pLeft = temp;
  // temp = new NODE(7);
  // bst->pRight->pRight = temp;

  // temp = new NODE(8);
  // bst->pLeft->pLeft->pLeft = temp;
  // temp = new NODE(9);
  // bst->pLeft->pLeft->pRight = temp;
  // temp = new NODE(10);
  // bst->pLeft->pRight->pLeft = temp;
  // temp = new NODE(11);
  // bst->pLeft->pRight->pRight = temp;
  // temp = new NODE(12);
  // bst->pRight->pLeft->pLeft = temp;
  // temp = new NODE(13);
  // bst->pRight->pLeft->pRight = temp;
  // temp = new NODE(14);
  // bst->pRight->pRight->pLeft = temp;
  // temp = new NODE(15);
  // bst->pRight->pRight->pRight = temp;

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
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "||                                               BINARY SEARCH TREE                                          ||" << std::endl;
    std::cout << "||                              -------------------------------------------------------                      ||" << std::endl;
    std::cout << "||                      1. Insert element                                                                    ||" << std::endl;
    std::cout << "||                      2. Delete element                                                                    ||" << std::endl;
    std::cout << "||                      3. Search element                                                                    ||" << std::endl;
    std::cout << "||                      4. Get height                                                                        ||" << std::endl;
    std::cout << "||                      5. Preorder (NLR) Traversal                                                          ||" << std::endl;
    std::cout << "||                      6. Inorder (LNR) Traversal                                                           ||" << std::endl;
    std::cout << "||                      7. Postorder (LRN) Traversal                                                         ||" << std::endl;
    std::cout << "||                      8. Print tree                                                                        ||" << std::endl;
    std::cout << "||                      0. Exits                                                                             ||" << std::endl;
    std::cout << "===============================================================================================================" << std::endl;

    choice = getUserChoice(1, 8, 0);

    switch (choice) {
      case 1: {
        int value;
        std::cout << "Input value: ";
        std::cin >> value;
        insertElement(bst, value);
        break;
      }
      case 2: {
      }
      case 3: {
        int target;
        std::cout << "Input number you want to find: ";
        std::cin >> target;
        NODE* result = searchItem(bst, target);
      } break;
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
      case 8:
        printBinaryTree(bst);
        break;
      default:
        break;
    }
  } while (choice != 0);
}

}  // namespace binarySearchTree