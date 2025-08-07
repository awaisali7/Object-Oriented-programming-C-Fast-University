//#include <iostream>
//using namespace std;
//int** AllocateMemory(int& rows, int& cols) {
//    cout << "Enter the number of rows: ";
//    cin >> rows;
//    cout << "Enter the number of columns: ";
//    cin >> cols;
//
//    int** matrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        matrix[i] = new int[cols];
//    }
//
//    return matrix;
//}
//
//void InitializeMatrix(int** matrix, const int& rows, const int& cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = 0;
//        }
//    }
//}
//
//void DisplayMatrix(int** matrix, const int& rows, const int& cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//void DeallocateMemory(int** matrix, const int& rows) {
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//
//int main() {
//    int rows, cols;
//
//    int** matrix = AllocateMemory(rows, cols);
//
//    InitializeMatrix(matrix, rows, cols);
//
//    cout << "Matrix:" << endl;
//    DisplayMatrix(matrix, rows, cols);
//
//    DeallocateMemory(matrix, rows);
//
//    return 0;
//}
