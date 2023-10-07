#include <iostream>

namespace binarySearchTree {

struct NODE {
  int data;
  NODE* left;
  NODE* right;
  NODE(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct BST {
  NODE* node;
  NODE* left;
  NODE* right;
  BST(int value) : node(value), left(nullptr), right(nullptr) {}
};

NODE* searchItem(NODE* &root, int target) {
  if (root == NULL) {
    return NULL;
  } else if ( root->data == target) {
    return root->data;
  }
  
  if (target < root->data) {
    return searchItem(root->left, target);
  } else {
    return searchItem(root->right, target);
  }
}

void insertElement(NODE*& root, int value) {
  if (root == NULL) {
    root = new NODE(value);
  }

  if (value < root->data) {
    insertElement(root->left, value);
  } else {
    insertElement(root->right, value);
  }
}

// NODE* deleteItem(NODE* &root, int key) {
//   if (root == nullptr) {
//     return nullptr;
//   }

//   if (key < root->value) {
//     root->left = deleteItem(root->left, key);
//   } else if (key > root->value) {
//     root->right = deleteItem(root->right, key);
//   } else {
//     if (root->left == nullptr) {
//       NODE* temp = root->right;
//       delete root;
//       return temp;
//     } else if (root->right == nullptr) {
//       NODE* temp = root->left;
//       delete root;
//       return temp;
//     }

//     NODE* temp = find(root->right);
//     root->value = temp->value;
//     root->right = deleteItem(root->right, temp->value);
//   }

//   return root;
// }

void handleBinarySearchTree() {
  NODE* bst = new NODE(NULL);
  int choice;
  do {
    cout << "===============================================================================================================" << endl;
    cout << "||                                               BINARY SEARCH TREE                                          ||" << endl;
    cout << "||                              -------------------------------------------------------                      ||" << endl;
    cout << "||                      1. Insert item                                                                       ||" << endl;
    cout << "||                      2. Remove item                                                                       ||" << endl;
    cout << "||                      3. Search item                                                                       ||" << endl;
    cout << "||                      4. Preorder (NLR) Traversal                                                          ||" << endl;
    cout << "||                      5. Inorder (LNR) Traversal                                                           ||" << endl;
    cout << "||                      6. Postorder (LRN) Traversal                                                         ||" << endl;
    cout << "||                      7. Print tree                                                                        ||" << endl;
    cout << "||                      0. Exits                                                                             ||" << endl;
    cout << "===============================================================================================================" << endl;

    choice = getUserChoice(1, 7, 0);

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
      // case 4:
      //   handleBinarySearchTree();
      //   break;
      default:
        break;
    }
  } while (choice != 0);
}

}  // namespace binarySearchTree