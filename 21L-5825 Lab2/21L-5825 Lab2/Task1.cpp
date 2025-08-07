#include <iostream>
#include <cstdlib>
using namespace std;

void populate_array(int** my_array, int m, int n) {
  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            my_array[i][j] = rand() % 100; // Generating random numbers between 0 and 99
        }
    }
}


void disp_array(int** my_array, int m, int n) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << my_array[i][j] << " ";
        }
        cout << endl;
    }
}


int** transpose_array(int** my_array, int m, int n) {
    int** transpose = new int*[n];
    for (int i = 0; i < n; i++) {
        transpose[i] = new int[m];
        for (int j = 0; j < m; j++) {
            transpose[i][j] = my_array[j][i];
        }
    }
    return transpose;
}


void deallocate_array(int** my_array, int m) {
    for (int i = 0; i < m; i++) {
        delete[] my_array[i];
    }
    delete[] my_array;
}

int main() {
    int m, n;
    cout << "Enter the size of the matrix m*n: ";
    cin >> m >> n;

 
    int** my_array = new int*[m];
    for (int i = 0; i < m; i++) {
        my_array[i] = new int[n];
    }


    populate_array(my_array, m, n);
    disp_array(my_array, m, n);


    int** transpose = transpose_array(my_array, m, n);
    cout << "Transpose Matrix:" << endl;
    disp_array(transpose, n, m);


    deallocate_array(my_array, m);
    deallocate_array(transpose, n);

    return 0;
}

