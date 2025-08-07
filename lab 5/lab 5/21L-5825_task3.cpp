#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    int* real;
    int* imaginary;

public:
    ComplexNumber(int r = 0, int i = 0) {
        real = new int;
        imaginary = new int;
        *real = r;
        *imaginary = i;
        cout << "Constructor Called: " << *real << " + " << *imaginary << "i" << endl;
    }

    ~ComplexNumber() {
        cout << "Destructor Called: " << *real << " + " << *imaginary << "i" << endl;
        delete real;
        delete imaginary;
    }

    void Input() {
        cout << "Enter the real part: ";
        cin >> *real;
        cout << "Enter the imaginary part: ";
        cin >> *imaginary;
    }

    void Output() {
        cout << *real << " + " << *imaginary << "i" << endl;
    }

    float Magnitude() {
        return sqrt(pow(*real, 2) + pow(*imaginary, 2));
    }
};

int main() {
    // Create a complex number on stack using default constructor
    ComplexNumber c1;
    c1.Input();
    cout << "Complex Number c1: ";
    c1.Output();

    // Create a ComplexNumber pointer on stack
    ComplexNumber* cPtr;

    // Check if it implicitly calls the constructor or not
    cPtr = new ComplexNumber(3, 5);
    cout << "Complex Number cPtr: ";
    cPtr->Output();

    // Create an array of five complex numbers on stack
    ComplexNumber arr[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter complex number " << i + 1 << ":" << endl;
        arr[i].Input();
    }

    // Display all the complex numbers and their magnitudes
    for (int i = 0; i < 5; i++) {
        cout << "Complex Number " << i + 1 << ": ";
        arr[i].Output();
        cout << "Magnitude: " << arr[i].Magnitude() << endl;
    }

    // Dynamically create an array of complex numbers
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    ComplexNumber* dynArr = new ComplexNumber[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter complex number " << i + 1 << ":" << endl;
        dynArr[i].Input();
    }

    // Display the complex numbers and their magnitudes
    for (int i = 0; i < size; i++) {
        cout << "Complex Number " << i + 1 << ": ";
        dynArr[i].Output();
        cout << "Magnitude: " << dynArr[i].Magnitude() << endl;
    }

    // Deallocate the dynamically allocated array
    delete[] dynArr;

    return 0;
}

