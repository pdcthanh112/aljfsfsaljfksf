#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int partition(int arr[], int left, int right) {
  int pivot = arr[right];
  int i = (left - 1);

  for (int j = left; j <= right - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]);
  return (i + 1);
}

void merge(int array[], int const left, int const mid, int const right) {
  int const subArrayOne = mid - left + 1;
  int const subArrayTwo = right - mid;

  auto *leftArray = new int[subArrayOne],
       *rightArray = new int[subArrayTwo];

  for (auto i = 0; i < subArrayOne; i++)
    leftArray[i] = array[left + i];
  for (auto j = 0; j < subArrayTwo; j++)
    rightArray[j] = array[mid + 1 + j];

  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    } else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }

  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }

  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int pi = partition(arr, left, right);

    quickSort(arr, left, pi - 1);
    quickSort(arr, pi + 1, right);
  }
}

void interchangeSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j])
        swap(arr[i], arr[j]);
    }
  }
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (arr[j] < arr[j - 1])
        swap(arr[j], arr[j - 1]);
    }
  }
}

void insertionSort(int arr[], int n) {
  int pos, x;
  for (int i = 1; i < n; i++) {
    x = arr[i];
    pos = i;
    while (pos > 0 && x < arr[pos - 1]) {
      arr[pos] = arr[pos - 1];
      pos--;
    }
    arr[pos] = x;
  }
}

void selectionSort(int arr[], int n) {
  int min;
  for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[min])
        min = j;
    if (min != i)
      swap(arr[min], arr[i]);
  }
}

void mergeSort(int array[], int const begin, int const end) {
  if (begin >= end)
    return;

  int mid = begin + (end - begin) / 2;
  mergeSort(array, begin, mid);
  mergeSort(array, mid + 1, end);
  merge(array, begin, mid, end);
}

void handleSort() {
  cout << "===============================================================================================================" << endl;
  cout << "||                                                     SORT                                                  ||" << endl;
  cout << "||                             -------------------------------------------------------                       ||" << endl;
  cout << "===============================================================================================================" << endl;

  int length;
  cout << "Input number of element: ";
  cin >> length;

  int arr[length];
  cout << "======== ARRAY DECLARATION ========" << endl;
  for (int i = 0; i < length; i++) {
    cout << "Element [" << i << "]: ";
    cin >> arr[i];
  }

  int choice;
  cout << "1. Quick sort" << endl;
  cout << "2. Interchange sort" << endl;
  cout << "3. Bubble sort" << endl;
  cout << "4. Insertion sort" << endl;
  cout << "5. Selection sort" << endl;
  cout << "Select sort algorithms:" << endl;
  cin >> choice;

  int index;
  switch (choice) {
    case 1:
      quickSort(arr, 0, length);
      break;
    case 2:
      interchangeSort(arr, length);
      break;
    case 3:
      bubbleSort(arr, length);
      break;
    case 4:
      insertionSort(arr, length);
      break;
    case 5:
      selectionSort(arr, length);
      break;
    default:
      break;
  }
}
