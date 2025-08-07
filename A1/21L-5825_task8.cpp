#include <iostream>
#include<cstring>
using namespace std;

// this function is used for maing the user enter the string.
char* get_String_Input() ;

//this function is used for cunting the frequencies of letters.
int* count_Letter_Frequencies(const char* input); 

//this function is used for printing the frequencies of letters.
void print_Letter_Frequencies(int* frequencies);

//this function is used for deallocation the memory.
void deallocate_Memory(char* str, int* frequencies);

int main() {
    char* input = get_String_Input(); 

    int* frequencies = count_Letter_Frequencies(input); 
    print_Letter_Frequencies(frequencies); 

    deallocate_Memory(input, frequencies); 

    system("Pause");
    return 0;
}
char* get_String_Input() {
    cout << "Enter the  string: ";
    char input[100];
    cin.getline(input, 100);

    // dynamically allocate memory for the string
    int length = strlen(input) + 1;
    char* str = new char[length];
    strcpy(str, input);

    return str;
}

int* count_Letter_Frequencies(const char* input) {
    // creating  an array to store letter frequencies.
    int* frequencies = new int[26];
    int i = 0;
    while (i < 26) {
        frequencies[i] = 0; // initialize all frequencies to zero
        i++;
    }

    int length = 0;
    while (input[length] != '\0') {
        char character = input[length++];
        if (character >= 'A' && character <= 'Z') {
            character = character - 'A' + 'a'; // converting  uppercase to lowercase letter.
        }
        if (character >= 'a' && character <= 'z') {
            int index = character - 'a';
            frequencies[index]++; // increment frequency for the similar letter.
        }
    }

    return frequencies;
}

void print_Letter_Frequencies(int* frequencies) {
    cout << " The letter frequency is following:" << endl;
    int i = 0;
    while (i < 26) {
        if (frequencies[i] > 0) {
            char letter = 'a' + i;
            cout << letter << " " << frequencies[i] << endl; // print letter and its frequency
        }
        i++;
    }
}

void deallocate_Memory(char* str, int* frequencies) {
    delete[] str; 
    delete[] frequencies;
}

