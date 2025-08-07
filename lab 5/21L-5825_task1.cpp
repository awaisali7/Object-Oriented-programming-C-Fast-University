#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    // Constructor
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Deep Copy Constructor
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Function to input matrix elements
    void input() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Function to print the matrix
    void print() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to transpose the matrix
    void transpose() {
        Matrix transposed(cols, rows);
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                transposed.data[i][j] = data[j][i];
            }
        }
        cout << "Transposed Matrix:" << endl;
        transposed.print();
    }
};

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Matrix matrix(rows, cols);

    matrix.input();

    matrix.print();

    matrix.transpose();

    return 0;
}

