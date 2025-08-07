#include <iostream>

using namespace std;

void getInput(int*& arr, int& size, int& count) {
    int input;
    while (true) {
        cin >> input;
        if (input == -1)
            break;
        *(arr + count) = input;
        count++;

        if (count == size) {
            // Array is full, double its size
            int* newArr = new int[size * 2];
            for (int i = 0; i < size; i++)
                *(newArr + i) = *(arr + i);
            delete[] arr;
            arr = newArr;
            size *= 2;
        }
    }
}

void displayReverse(const int* arr, int count) {
    for (int i = count - 1; i >= 0; i--)
        cout << *(arr + i) << " ";
    cout << endl;
}

int main() {
    int size = 5;
    int* arr = new int[size];
    int count = 0;

    cout << "Enter integers (enter -1 to stop): " << endl;
    getInput(arr, size, count);

    cout << "Reversed input: ";
    displayReverse(arr, count);

    delete[] arr;
    return 0;
}

