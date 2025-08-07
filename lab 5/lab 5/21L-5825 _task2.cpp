#include <iostream>
#include <string>

using namespace std;

class Holiday {
private:
    string name;
    int day;
    string month;

public:
    Holiday() : name(""), day(0), month("") {}

    Holiday(const string& n, int d, const string& m) : name(n), day(d), month(m) {}

    bool setName(const string& s) {
        if (s.length() <= 50) {
            name = s;
            return true;
        }
        return false;
    }

    string getName() const {
        return name;
    }

    bool setDay(int u) {
        if (u >= 0) {
            day = u;
            return true;
        }
        return false;
    }

    int getDay() const {
        return day;
    }

    bool setMonth(const string& p) {
        if (p.length() <= 10) {
            month = p;
            return true;
        }
        return false;
    }

    string getMonth() const {
        return month;
    }
};

bool inSameMonth(const Holiday& a, const Holiday& b) {
    return a.getMonth() == b.getMonth();
}

double avgDate(Holiday arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i].getDay();
    }
    return sum / size;
}

int main() {
    Holiday h1; // Default constructor
    h1.setName("New Year");
    h1.setDay(1);
    h1.setMonth("January");

    cout << "Holiday 1: " << h1.getName() << " - " << h1.getDay() << " " << h1.getMonth() << endl;

    Holiday h2("Eid", 27, "June"); // Parameterized constructor

    cout << "Holiday 2: " << h2.getName() << " - " << h2.getDay() << " " << h2.getMonth() << endl;

    // Usage of inSameMonth function
    if (inSameMonth(h1, h2)) {
        cout << "Holiday 1 and Holiday 2 are in the same month." << endl;
    } else {
        cout << "Holiday 1 and Holiday 2 are not in the same month." << endl;
    }

    // Usage of avgDate function
    Holiday arr[] = {h1, h2};
    int size = sizeof(arr) / sizeof(arr[0]);
    double avg = avgDate(arr, size);

    cout << "Average date of the holidays: " << avg << endl;

    return 0;
}

