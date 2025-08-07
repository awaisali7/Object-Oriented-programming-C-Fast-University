#include <iostream>
using namespace std;
void mergeArrays(const int* arr1, int size1, const int* arr2, int size2, int* mergedArr) {
    int i = 0;                          // Index for arr1
    int j = size2 - 1;                  // Index for arr2
    int k = 0;                          // Index for mergedArr

    while (i < size1 && j >= 0) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        }
        else {
            mergedArr[k] = arr2[j];
            j--;
        }
        k++;
    }

    // Copy the remaining elements from arr1, if any
    while (i < size1) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy the remaining elements from arr2, if any
    while (j >= 0) {
        mergedArr[k] = arr2[j];
        j--;
        k++;
    }
}

void displayArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;

    cout << "Enter the size of the ascending array: ";
    cin >> size1;
    int* arr1 = new int[size1];
    cout << "Enter the elements of the ascending array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the descending array: ";
    cin >> size2;
    int* arr2 = new int[size2];
    cout << "Enter the elements of the descending array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int* mergedArr = new int[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, mergedArr);

    cout << "Merged array in ascending order: ";
    displayArray(mergedArr, size1 + size2);

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;

    return 0;
}
