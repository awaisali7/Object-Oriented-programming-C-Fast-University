#include <iostream>
using namespace std;

// this function is used to input the array elements
void get_Input(int*& arr, int& size) ;

// this function is used  to find the common elements between two arrays
int* find_the_CommonElements(const int* array1, int size1, const int* array2, int size2, int& newSize); 

// this function is used to display the elements of an array
void display_Array(const int* arr, int size) ;

//this function is used to deallocate memory for arrays
void deallocate_Arrays(int* arr1, int* arr2, int* commonArr);

int main() {
    int* array1 = NULL;
    int size1;
    cout<<"*******ARRAY 1*******"<<endl;
    get_Input(array1, size1);

    cout<<"*******ARRAY 2*******"<<endl;
    int* array2 = NULL;
    int size2;
    get_Input(array2, size2);

    int newSize;
    int* commonArray = find_the_CommonElements(array1, size1, array2, size2, newSize); // Find common elements

    cout << "The Common elements are: ";
    display_Array(commonArray, newSize); // display common elements

    deallocate_Arrays(array1, array2, commonArray); // deallocate memory for arrays

    return 0;
}
void get_Input(int*& arr, int& size) {
    cout << "Enter the size of the array: ";
    cin >> size;
	while(size<=0){  // for positive integer as array size
    			cout<<"Enter a positive integer as size of array:"<<endl;
    			cin>>size;
			}
	
    arr = new int[size]; // allocate memory for the array

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> *(arr + i);
    }

  
}
int* find_the_CommonElements(const int* array1, int size1, const int* array2, int size2, int& newSize) {
    int* commonArray = new int[size1 + size2]; // Allocate memory for the common elements array
    int count = 0; // Number of common elements found

    for (int i = 0; i < size1; i++) {
    	
        for (int j = 0; j < size2; j++) {
        	
            if (*(array1 + i) == *(array2 + j)) {
                bool isDuplicate = false;
                for (int k = 0; k < count; k++) {
                    if (*(array1 + i) == *(commonArray + k)) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    *(commonArray + count) = *(array1 + i);
                    count++;
                }
                break;
            }
        }
    }

    newSize = count;
    return commonArray;
}

void display_Array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}


void deallocate_Arrays(int* arr1, int* arr2, int* commonArr) {
    delete[] arr1; 
    delete[] arr2; 
    delete[] commonArr; 
}

