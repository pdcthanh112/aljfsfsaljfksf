#include <iostream>

struct NODE {
  int value;
  int balance;
  NODE* left;
  NODE* right;
  NODE(int value) : value(value), left(nullptr), right(nullptr) {}
};