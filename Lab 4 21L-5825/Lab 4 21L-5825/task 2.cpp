#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool availability;

public:
    Book() {
        title = "";
        author = "";
        availability = true;
    }

    Book(string title, string author, bool availability) {
        this->title = title;
        this->author = author;
        this->availability = availability;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool getAvailability() const {
        return availability;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    void setAvailability(bool availability) {
        this->availability = availability;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Sorry, the book is currently unavailable." << endl;
        }
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", true);

    cout << "Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "Availability: " << (book1.getAvailability() ? "Available" : "Not Available") << endl;

    book1.borrowBook();

    return 0;
}

