#include <iostream>
using namespace std;

typedef struct node NODE;
struct node {
  int value;
  int color;  // 0: black, 1: red
  NODE* left;
  NODE* right;
  NODE(int x) : value(x), left(nullptr), right(nullptr) {}
};