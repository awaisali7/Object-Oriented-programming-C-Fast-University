#include <iostream>

using namespace std;

bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}


char** AllocateMemory(int& rows, int& cols) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    char** matrix = new char*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
    }

    return matrix;
}


void InputMatrix(char** matrix, const int rows, const int cols) {
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}


void DisplayMatrix(char** matrix, const int& rows, const int& cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void SeparateElements(char** matrix, const int rows, const int cols, char*& alphabets, char*& numbers, char*& specialchar) {
    const int MAX_SIZE = rows * cols;
    alphabets = new char[MAX_SIZE];
    numbers = new char[MAX_SIZE];
    specialchar = new char[MAX_SIZE];

    int alphabetsIndex = 0;
    int numbersIndex = 0;
    int specialcharIndex = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char ch = matrix[i][j];
            if (isAlpha(ch)) {
                alphabets[alphabetsIndex++] = ch;
            } else if (isDigit(ch)) {
                numbers[numbersIndex++] = ch;
            } else {
                specialchar[specialcharIndex++] = ch;
            }
        }
    }

   
    alphabets[alphabetsIndex] = '\0';
    numbers[numbersIndex] = '\0';
    specialchar[specialcharIndex] = '\0';
}

int main() {
    int rows, cols;
    char** matrix = AllocateMemory(rows, cols);

    InputMatrix(matrix, rows, cols);

    DisplayMatrix(matrix, rows, cols);

    char* alphabets;
    char* numbers;
    char* specialchar;

    SeparateElements(matrix, rows, cols, alphabets, numbers, specialchar);

   
    cout << "Alphabets: " << alphabets << endl;
    cout << "Numbers: " << numbers << endl;
    cout << "Special Characters: " << specialchar << endl;

   
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] alphabets;
    delete[] numbers;
    delete[] specialchar;

    return 0;
}

