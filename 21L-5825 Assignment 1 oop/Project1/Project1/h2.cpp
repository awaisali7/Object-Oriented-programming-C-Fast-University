#include <iostream>

using namespace std;

int* compressArray(const int* arr, int size, int& newSize) {
    int* compressedArr = new int[size];  // Allocate memory for the compressed array
    int count = 0;  // Number of elements in the compressed array

    for (int i = 0; i < size; i++) {
        if (i == 0 || *(arr + i) != *(arr + i - 1)) {
            *(compressedArr + count) = *(arr + i);
            count++;
        }
    }

    newSize = count;
    return compressedArr;
}

void displayArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }

    int compressedSize;
    int* compressedArr = compressArray(arr, size, compressedSize);

    cout << "Compressed array: ";
    displayArray(compressedArr, compressedSize);

    delete[] arr;
    delete[] compressedArr;

    return 0;
}

