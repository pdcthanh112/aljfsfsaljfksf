#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
using namespace std;

#define CONFIRM_YES 'Y'
#define CONFIRM_NO 'N'

void showArray(int arr[], int length) {
  cout << "[";
  for (int i = 0; i < length; i++) {
    cout << arr[i];
    if (i < length - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}

int getUserChoice(int min, int max, int exitsCode) {
  int choice;
  cout << "Input your choice: ";
  cin >> choice;

  while (!(choice >= min && choice <= max || choice == exitsCode)) {
    cout << "Please input [" << min << " -> " << max <<  "](or " << exitsCode << " to exist): ";
    cin >> choice;
  }
  return choice;
}

bool getUserConfirmation() {
  char confirm;
  cout << "Do you want to continue: Yes(Y), No(N): ";
  cin >> confirm;
  while (confirm != CONFIRM_YES && confirm != CONFIRM_NO) {
    cout << "Please choose (Y) or (N): ";
    cin >> confirm;
  }
  return confirm == CONFIRM_YES;
}

#endif 
