#include <iostream>

using namespace std;

void myTokenizer(char* data, char** list_tokens, char delimiter) {
    int token_index = 0;
    int start_index = 0;
    int i = 0;

    while (data[i] != '\0') {
        if (data[i] == delimiter) {
            int token_length = i - start_index;
            list_tokens[token_index] = new char[token_length + 1];
            for (int j = 0; j < token_length; j++) {
                list_tokens[token_index][j] = data[start_index + j];
            }
            list_tokens[token_index][token_length] = '\0';
            token_index++;
            start_index = i + 1;
        }
        i++;
    }

   
    int token_length = i - start_index;
    list_tokens[token_index] = new char[token_length + 1];
    for (int j = 0; j < token_length; j++) {
        list_tokens[token_index][j] = data[start_index + j];
    }
    list_tokens[token_index][token_length] = '\0';
}

int main() {
    char data[100] ;
    cout<<"Enter: ";
    cin.getline(data,100,'\n');
    char delimiter = ',';
    const int MAX_TOKENS = 10;

    char* list_tokens[MAX_TOKENS] = { 0};

    myTokenizer(data, list_tokens, delimiter);

   
    cout << "Tokens are:" << endl;
    for (int i = 0; list_tokens[i] != 0; i++) {
        cout << list_tokens[i] << endl;
        delete[] list_tokens[i];
    }

    return 0;
}
