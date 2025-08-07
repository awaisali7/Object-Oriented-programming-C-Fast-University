#include <iostream>

using namespace std;

// this  function is used to input the elements in the 2D array.
void input_Array(int** arr, int rows, int* colsArr);

// this function is used  to pass elements of 2D array into a 1D array.
int* twoDim_ToOneDim(int** arr, int rows, const int* colsArr, int* size);

// this function to sort the 1D array.
void sort_Array(int* arr, int size);

// this  function used to display the sorted 1D array in ascending order.
void display_Array(const int* arr, int size);

// this function is used to deallocate the memory.
void deallocate_Memory(int** arr, int rows, const int* colsArr, int* oneDimArr);

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    int** arr = new int*[rows];
    int* colsArr = new int[rows];

    input_Array(arr, rows, colsArr);

    int size;
    int* oneDimArr = twoDim_ToOneDim(arr, rows, colsArr, &size);

    sort_Array(oneDimArr, size);

    display_Array(oneDimArr, size);

   
    deallocate_Memory(arr, rows, colsArr, oneDimArr);

    return 0;
}


void input_Array(int** arr, int rows, int* colsArr) {
    int i = 0;
    while (i < rows) {
        int cols;
        cout << "Enter the number of columns for row " << i + 1 << ": ";
        cin >> cols;

        arr[i] = new int[cols];
        colsArr[i] = cols;

        int j = 0;
        while (j < cols) {
            int value;
            cout << "Enter a positive value for arr[" << i << "][" << j << "]: ";
            cin >> value;

            // for making sure user enters a positive value.
            while (value <= 0) {
                cout << "Invalid input! Enter a positive value: ";
                cin >> value;
            }

            arr[i][j] = value;
            j++;
        }
        i++;
    }
}


int* twoDim_ToOneDim(int** arr, int rows, const int* colsArr, int* size) {
    int totalElements = 0;
    for (int i = 0; i < rows; i++) {
        totalElements += colsArr[i];
    }

    *size = totalElements;

    int* newArr = new int[totalElements];
    int index = 0;

    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < colsArr[i]) {
            newArr[index] = arr[i][j];
            index++;
            j++;
        }
        i++;
    }

    return newArr;
}


void sort_Array(int* arr, int size) {
    int i = 0;
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}


void display_Array(const int* arr, int size) {
    cout << endl;
    cout << "Contents of the sorted 1D array are:" << endl;
    int i = 0;
    while (i < size) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}


void deallocate_Memory(int** arr, int rows, const int* colsArr, int* oneDimArr) {
    int i = 0;
    while (i < rows) {
        delete[] arr[i];
        i++;
    }
    delete[] arr;
    delete[] colsArr;
    delete[] oneDimArr;
}
