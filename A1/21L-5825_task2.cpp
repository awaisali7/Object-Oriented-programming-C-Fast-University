#include <iostream>

using namespace std;

// this function is used to compress the input array by removing consecutive duplicate entries.
int* compress_Array(const int* input, int size, int& newSize);

// this function is used to display the elements of an array.
void display_Array(const int* arr, int size) ;

// this function is used  to get user input for an array.
void get_User_Input(int* arr, int size); 

// this function to deallocate memory for a dynamically allocated array.
void deallocate_Memory(int* arr);

int main() {
    int size;
    cout << "Enter the size of the array: "<<endl;
    cin >> size;
    
    		while(size<=0){  // for positive integer as array size.
    			cout<<"Enter a positive integer as size of array:"<<endl;
    			cin>>size;
			}
	

    int* input = new int[size];  
    get_User_Input(input, size);  

    int compressedSize;
    int* compressed = compress_Array(input, size, compressedSize); 

    cout << "Input array: ";
    display_Array(input, size);  

    cout << "Compressed array: ";
    display_Array(compressed, compressedSize);  // display the compressed array.

    // deallocate memory for both input and compressed arrays.
    deallocate_Memory(input), deallocate_Memory(compressed);

    return 0;
}
int* compress_Array(const int* input, int size, int& newSize) {
    int* compressed = new int[size];  // allocate memory for the compressed array.
    int count = 0;  // number of elements in the compressed array.

    for (int i = 0; i < size; i++) {
        if (i == 0 || *(input + i) != *(input + i - 1)) {
            *(compressed + count) = *(input + i);
            count++;
        }
    }

    newSize = count;
    return compressed;
}

void display_Array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void get_User_Input(int* arr, int size) {
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element: " << i + 1 << ": ";
        cin >> *(arr + i);
    }
}

void deallocate_Memory(int* arr) {
    delete[] arr;
}
