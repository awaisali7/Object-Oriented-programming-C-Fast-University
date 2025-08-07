#include <iostream>
using namespace std;

// this function used to allocate memory for the matrix
int** Allocate_Memory(int& rows, int& cols);

//this  function is used to initialize the matrix with zeros
void Initialize_Matrix(int** matrix, const int& rows, const int& cols);

// this function is used  to display the matrix
void Display_Matrix(int** matrix, const int& rows, const int& cols) ;

// this function is used to deallocate memory for the matrix.
void Deallocate_Memory(int** matrix, const int& rows);

int main() {
    int rows, cols;

    // allocate memory for the matrix
    int** matrix = Allocate_Memory(rows, cols);

    // initialize the matrix with zeros
    Initialize_Matrix(matrix, rows, cols);

    cout << "Matrix:" << endl;
   
    Display_Matrix(matrix, rows, cols);

   
    Deallocate_Memory(matrix, rows);

    return 0;
}

int** Allocate_Memory(int& rows, int& cols) {
    
	cout << "Enter the number of rows: ";
    cin >> rows;
    while(rows<=0){
    	cout<<"Enter the a positive integer for rows"<<endl;
    	cin>>rows;
	}
    cout << "Enter the number of columns: ";
    cin >> cols;
     while(cols<=0){
    	cout<<"Enter the a positive integer for cols"<<endl;
    	cin>>cols;
	}

    // allocate memory for the matrix
    int** matrix = new int*[rows];
    int i = 0;
    while (i < rows) {
        matrix[i] = new int[cols];
        i++;
    }

    return matrix;
}


void Initialize_Matrix(int** matrix, const int& rows, const int& cols) {
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            *(*(matrix + i) + j) = 0; // set each element to 0
            j++;
        }
        i++;
    }
}


void Display_Matrix(int** matrix, const int& rows, const int& cols) {
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            cout << *(*(matrix + i) + j) << " "; // display each element
            j++;
        }
        cout << endl; // move to the next row
        i++;
    }
}


void Deallocate_Memory(int** matrix, const int& rows) {
    int i = 0;
    while (i < rows) {
        delete[] matrix[i]; // deallocate memory for each row
        i++;
    }
    delete[] matrix; // deallocate memory for the array of pointers
}

