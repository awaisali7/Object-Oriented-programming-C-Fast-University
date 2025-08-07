#include <iostream>

using namespace std;
// this function is used to take input from the user till he enters -1.
void populate_the_Array(int* &arr, int& size, int& count);

// this function is used to display the reverse order of the element entered by user.
void display_Reverse(const int* arr, int count); 

//this function is used to deallocate memory.
void deallocate_Array(int* arr);

int main() {
    int initialSize = 5; // initial size of the array is 5.
    int* dynamicArray = new int[initialSize]; // declaring the dynamic array pointer.
    int elementCount = 0; // number of elements entered

    populate_the_Array(dynamicArray, initialSize, elementCount); //this function takes values from the user until he enters -1.
    display_Reverse(dynamicArray, elementCount); // this function displays the elements in reverse order.
    deallocate_Array(dynamicArray); // this function deallocates the memory.

    return 0;
}
void populate_the_Array(int* &arr, int& size, int& count) {
    int num;
    cout << "Enter integers (enter -1 to stop): ";

    while (true) {
        cin >> num;
        if (num == -1)
            break;
        *(arr + count) = num; 
        count++;

        if (count == size) {
            // when array is full the size is doubled
            int* newArr = new int[size * 2];
            for (int i = 0; i < size; i++)
                *(newArr + i) = *(arr + i); // copying the elements to the new array.
            delete[] arr;
            arr = newArr;
            size *= 2;
        }
    }
}

void display_Reverse(const int* arr, int count) {
    cout << "Reversed input: ";
    for (int i = count - 1; i >= 0; i--)
        cout << *(arr + i) << " "; // for accessing and displaying the elements in reverse oreder.
    cout << endl;
}


void deallocate_Array(int* arr) {
    delete[] arr; // deallocation of  the  memory.
}
