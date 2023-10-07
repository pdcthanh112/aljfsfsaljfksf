#include <iostream>
using namespace std;

typedef struct node NODE;
struct node {
  int value;
  int balance;
  NODE* left;
  NODE* right;
  NODE(int x) : value(x), left(nullptr), right(nullptr) {}
};