#include <iostream>

struct NODE {
  int value;
  int color;  // 0: black, 1: red
  NODE* pLeft;
  NODE* pRight;
  NODE(int x) : value(x), pLeft(nullptr), pRight(nullptr) {}
};