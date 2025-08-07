#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Pizza {
private:
    string size;
    int cheeseToppings;
    int pepperoniToppings;
    int hamToppings;

public:
    Pizza() {
        size = "";
        cheeseToppings = 0;
        pepperoniToppings = 0;
        hamToppings = 0;
    }

    Pizza(string size, int cheeseToppings, int pepperoniToppings, int hamToppings) {
        this->size = size;
        this->cheeseToppings = cheeseToppings;
        this->pepperoniToppings = pepperoniToppings;
        this->hamToppings = hamToppings;
        cout << "Overloaded/parameterized Constructor Called" << endl;
    }

    double calcCost() const {
        double cost = 0.0;

        if (size == "small") {
            cost = 10.0;
        } else if (size == "medium") {
            cost = 12.0;
        } else if (size == "large") {
            cost = 14.0;
        }

        cost += 2.0 * (cheeseToppings + pepperoniToppings + hamToppings);

        return cost;
    }

    string getDescription() const {
        stringstream ss;
        ss << "Pizza Size: " << size << "\n";
        ss << "Cheese Toppings: " << cheeseToppings << "\n";
        ss << "Pepperoni Toppings: " << pepperoniToppings << "\n";
        ss << "Ham Toppings: " << hamToppings << "\n";

        return ss.str();
    }

    string getSize() const {
        return size;
    }

    int getCheeseToppings() const {
        return cheeseToppings;
    }

    int getPepperoniToppings() const {
        return pepperoniToppings;
    }

    int getHamToppings() const {
        return hamToppings;
    }

    void setSize(string size) {
        this->size = size;
    }

    void setCheeseToppings(int cheeseToppings) {
        this->cheeseToppings = cheeseToppings;
    }

    void setPepperoniToppings(int pepperoniToppings) {
        this->pepperoniToppings = pepperoniToppings;
    }

    void setHamToppings(int hamToppings) {
        this->hamToppings = hamToppings;
    }
};

int main() {
    Pizza pizza1("large", 1, 1, 2);

    cout << pizza1.getDescription() << endl;
    cout << "Cost: $" << pizza1.calcCost() << endl;

    return 0;
}

