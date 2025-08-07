#include <iostream>
using namespace std;

// this function is used to input elements into the matrix.
void input_the_Matrix_Elements(int** matrix, int rows, int cols);

//this  function to remove zero elements from the matrix and create a new matrix with non-zero elements.
int** remove_the_Zeros(int** matrix, int rows, int cols, int& nonZeroRows, int& nonZeroCols);

// this function is used to display the matrix.
void display_Matrix(int** matrix, int rows, int cols);

// this function to deallocate the memory allocated for the matrix.
void deallocate_Memory(int** matrix, int rows);

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }


    input_the_Matrix_Elements(matrix, rows, cols);

    int nonZeroRows, nonZeroCols;
   
    int** nonZeroMatrix = remove_the_Zeros(matrix, rows, cols, nonZeroRows, nonZeroCols);

    cout << "Original Matrix:" << endl;
    // Display the original matrix
    display_Matrix(matrix, rows, cols);

    cout << "New Matrix without zeros:" << endl;
    // Display the new matrix with non-zero elements
    display_Matrix(nonZeroMatrix, nonZeroRows, nonZeroCols);

    // Deallocate memory
    deallocate_Memory(matrix, rows);
    deallocate_Memory(nonZeroMatrix, nonZeroRows);

    return 0;
}

void input_the_Matrix_Elements(int** matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            cin >> *(*(matrix + i) + j);
            j++;
        }
        i++;
    }
}


int** remove_the_Zeros(int** matrix, int rows, int cols, int& nonZeroRows, int& nonZeroCols) {
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(*(matrix + i) + j) != 0) {
                nonZeroCount++;
            }
        }
    }

    // for calculating  the dimensions of the new matrix with non-zero elements.
    nonZeroRows = nonZeroCount / cols;
    nonZeroCols = cols;

    if (nonZeroCount % cols != 0) {
        nonZeroRows++;
        nonZeroCols = nonZeroCount % cols;
    }

   
    int** newMatrix = new int*[nonZeroRows];
    for (int i = 0; i < nonZeroRows; i++) {
        newMatrix[i] = new int[nonZeroCols];
    }

   
    int newRow = 0, newCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(*(matrix + i) + j) != 0) {
                *(*(newMatrix + newRow) + newCol) = *(*(matrix + i) + j);
                newCol++;
                if (newCol == nonZeroCols) {
                    newCol = 0;
                    newRow++;
                }
            }
        }
    }

    return newMatrix;
}

void display_Matrix(int** matrix, int rows, int cols) {
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            cout << *(*(matrix + i) + j) << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}


void deallocate_Memory(int** matrix, int rows) {
    int i = 0;
    while (i < rows) {
        delete[] matrix[i];
        i++;
    }
    delete[] matrix;
}



