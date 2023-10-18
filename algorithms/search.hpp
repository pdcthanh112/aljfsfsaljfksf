#include <math.h>

#include <iostream>

#include "../utils.hpp"

int linearSearch(int arr[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int binarySearch(int arr[], int left, int right, int target) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return mid;
    } else {
      if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return -1;
}

int ternarySearch(int arr[], int left, int right, int target) {
  if (right >= left) {
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == target) {
      return mid1;
    }
    if (arr[mid2] == target) {
      return mid2;
    }
    if (target < arr[mid1]) {
      return ternarySearch(arr, left, mid1 - 1, target);
    } else if (target > arr[mid2]) {
      return ternarySearch(arr, mid2 + 1, right, target);
    } else {
      return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }
  }
  return -1;
}

int jumpSearch(int arr[], int n, int target) {
  int step = sqrt(n);
  int prev = 0;

  while (arr[std::min(step, n) - 1] < target) {
    prev = step;
    step += sqrt(n);
    if (prev >= n)
      return -1;
  }

  while (arr[prev] < target) {
    prev++;
    if (prev == std::min(step, n))
      return -1;
  }

  if (arr[prev] == target) {
    return prev;
  }

  return -1;
}

int recursiveSearch(int arr[], int left, int right, int target) {
  if (left > right)
    return -1;
  int mid = (left + right) / 2;
  if (arr[mid] == target) {
    return mid;
  }

  if (arr[mid] > target) {
    return recursiveSearch(arr, left, mid - 1, target);
  } else {
    return recursiveSearch(arr, mid + 1, right, target);
  }
}

void handleSearch() {
  bool confirm;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                   SEARCH                                                  ||\n";
    std::cout << "||                             -------------------------------------------------------                       ||\n";
    std::cout << "===============================================================================================================\n";

    std::cout << "_____Select search algorithms_______\n";
    std::cout << "1. Linear search\n";
    std::cout << "2. Binary search\n";
    std::cout << "3. Ternary search\n";
    std::cout << "4. Jump search\n";
    std::cout << "5. Recursive search\n";
    int choice;
    std::cout << "Input your choice: ";
    std::cin >> choice;

    std::cout << "========= ARRAY DECLARATION ==========\n";
    int length;
    std::cout << "Input number of element: ";
    std::cin >> length;

    int arr[length];
    for (int i = 0; i < length; i++) {
      std::cout << "Element at position [" << i << "]: ";
      std::cin >> arr[i];
    }
    showArray(arr, length);

    int target;
    std::cout << "\nInput number you want to find: ";
    std::cin >> target;

    int index;
    switch (choice) {
      case 1:
        index = linearSearch(arr, length, target);
        break;
      case 2:
        index = binarySearch(arr, 0, length - 1, target);
        break;
      case 3:
        index = ternarySearch(arr, 0, length - 1, target);
        break;
      case 4:
        index = jumpSearch(arr, length, target);
        break;
      case 5:
        index = recursiveSearch(arr, 0, length - 1, target);
        break;
      default:
        break;
    }

    if (index == -1) {
      std::cout << "===> Not exits\n";
    } else {
      std::cout << "===> Result at position: " << index << std::endl;
    }

    confirm = getUserConfirmation();

    if (confirm) {
      system("cls");
    } else {
      break;
    }
  } while (confirm);
}
