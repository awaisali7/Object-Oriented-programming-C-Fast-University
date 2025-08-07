#include <iostream>

using namespace std;

void inputArray(int** arr, int rows, int* colsArr) {
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

            while (value <= 0) {
                cout << "Invalid input! Enter a positive value: ";
                cin >> value;
            }

            *( *(arr + i) + j) = value;
            j++;
        }
        i++;
    }
}

int* twoDimToOneDim(int** arr, int rows, const int* colsArr, int* size) {
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
            *(newArr + index) = *( *(arr + i) + j);
            index++;
            j++;
        }
        i++;
    }

    return newArr;
}

void sortArray(int* arr, int size) {
    int i = 0;
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
            j++;
        }
        i++;
    }
}

void displayArray(const int* arr, int size) {
	cout<<endl<<endl<<"              ******************"<<endl;
    cout << "Contents of the 1D sorted array are : "<<endl;
    int i = 0;
    while (i < size) {
        cout << *(arr + i) << " ";
        i++;
    }
    cout << endl;
    
    cout<<"              *******************"<<endl;
}

void deallocateMemory(int** arr, int rows, const int* colsArr, int* oneDimArr) {
    int i = 0;
    while (i < rows) {
        delete[] arr[i];
        i++;
    }
    delete[] arr;
    delete[] colsArr;
    delete[] oneDimArr;
}

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    int** arr = new int*[rows];
    int* colsArr = new int[rows];

    inputArray(arr, rows, colsArr);

    int size;
    int* oneDimArr = twoDimToOneDim(arr, rows, colsArr, &size);

    sortArray(oneDimArr, size);

    displayArray(oneDimArr, size);

    // Deallocate memory
    deallocateMemory(arr, rows, colsArr, oneDimArr);

    return 0;
}

