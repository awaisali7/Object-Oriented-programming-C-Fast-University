#include <iostream>
using namespace std;

// this function is used to input elements for the ascending array.
void input_Ascending_Array(int* arr, int size);

// this function is used to input elements for the descending array.
void input_Descending_Array(int* arr, int size);

//this  function is used to merge two arrays in ascending order.
void merge_Arrays(const int* arr1, int size1, const int* arr2, int size2, int* mergedArr);

// this function is usedto display the elements of an array.
void display_Array(const int* arr, int size) ;

//this function is used  to deallocate memory for the arrays.
void deallocate_Arrays(int* arr1, int* arr2, int* mergedArr);

int main() {
    int size1, size2;

    // input size and elements for the ascending array
    cout << "Enter the size of the ascending array: ";
    cin >> size1;
    int* arr1 = new int[size1];
    input_Ascending_Array(arr1, size1);

    // input size and elements for the descending array.
    cout << "Enter the size of the descending array: ";
    cin >> size2;
    int* arr2 = new int[size2];
    input_Descending_Array(arr2, size2);

    int* mergedArr = new int[size1 + size2];

   
    merge_Arrays(arr1, size1, arr2, size2, mergedArr);

    cout << "Merged array in ascending order: ";
    display_Array(mergedArr, size1 + size2);

 
    deallocate_Arrays(arr1, arr2, mergedArr);

    return 0;
}
void input_Ascending_Array(int* arr, int size) {
    cout << "Enter the elements of the ascending array: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
}


void input_Descending_Array(int* arr, int size) {
    cout << "Enter the elements of the descending array: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
}


void merge_Arrays(const int* arr1, int size1, const int* arr2, int size2, int* mergedArr) {
    int i = 0; // index for arr1.
    int j = size2 - 1; // index for arr2.
    int k = 0; // index for mergedArr.

    while (i < size1 && j >= 0) {
        if (*(arr1 + i) <= *(arr2 + j)) {
            *(mergedArr + k) = *(arr1 + i);
            i++;
        }
        else {
            *(mergedArr + k) = *(arr2 + j);
            j--;
        }
        k++;
    }

    // copy the remaining elements from arr1 if any
    while (i < size1) {
        *(mergedArr + k) = *(arr1 + i);
        i++;
        k++;
    }

    // copy the remaining elements from arr2 if any
    while (j >= 0) {
        *(mergedArr + k) = *(arr2 + j);
        j--;
        k++;
    }
}


void display_Array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}


void deallocate_Arrays(int* arr1, int* arr2, int* mergedArr) {
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;
}

