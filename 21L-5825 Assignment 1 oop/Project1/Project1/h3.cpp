#include <iostream>
using namespace std;
int* findCommonElements(const int* arr1, int size1, const int* arr2, int size2, int& newSize) {
    int* commonArr = new int[size1 + size2]; // Allocate memory for the common elements array
    int count = 0; // Number of common elements found

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                bool isDuplicate = false;
                for (int k = 0; k < count; k++) {
                    if (arr1[i] == commonArr[k]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    commonArr[count] = arr1[i];
                    count++;
                }
                break;
            }
        }
    }

    newSize = count;
    return commonArr;
}

void displayArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;
    cout << "Enter the size of array1: ";
    cin >> size1;
    cout << "Enter the size of array2: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    cout << "Enter the elements of array1: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of array2: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int newSize;
    int* commonArr = findCommonElements(arr1, size1, arr2, size2, newSize);

    cout << "Common elements: ";
    displayArray(commonArr, newSize);

    delete[] arr1;
    delete[] arr2;
    delete[] commonArr;

    return 0;
}
