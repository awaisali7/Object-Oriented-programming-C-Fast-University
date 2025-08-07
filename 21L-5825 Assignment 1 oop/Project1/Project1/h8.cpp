#include <iostream>
#include <cstring>

int* countLetters(const std::string& str) {
    int* frequency = new int[26] {0}; // Initialize the array with zeros

    for (char c : str) {
        if (std::isalpha(c)) { // Check if the character is a letter
            c = std::tolower(c); // Convert to lowercase
            frequency[c - 'a']++; // Increment the count for the corresponding letter
        }
    }

    return frequency;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int* letterCounts = countLetters(input);

    std::cout << "Frequency of letters:\n";
    for (int i = 0; i < 26; i++) {
        if (letterCounts[i] > 0) {
            char letter = 'a' + i;
            std::cout << letter << ": " << letterCounts[i] << std::endl;
        }
    }

    delete[] letterCounts;

    return 0;
}


