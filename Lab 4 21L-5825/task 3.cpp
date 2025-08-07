#include <iostream>
#include <string>

using namespace std;

class CartItem {
private:
    string productName;
    int quantity;
    double pricePerItem;

public:
    CartItem() {
        productName = "";
        quantity = 0;
        pricePerItem = 0.0;
    }

    CartItem(string productName, int quantity, double pricePerItem) {
        this->productName = productName;
        this->quantity = quantity;
        this->pricePerItem = pricePerItem;
    }

    ~CartItem() {
        cout << "CartItem destructor called." << endl;
    }

    string getProductName() const {
        return productName;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPricePerItem() const {
        return pricePerItem;
    }

    void setProductName(string productName) {
        this->productName = productName;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void setPricePerItem(double pricePerItem) {
        this->pricePerItem = pricePerItem;
    }

    double calculateTotalPrice() const {
        return quantity * pricePerItem;
    }
};

int main() {
    CartItem item1("iPhone 12", 2, 999.99);

    cout << "Product Name: " << item1.getProductName() << endl;
    cout << "Quantity: " << item1.getQuantity() << endl;
    cout << "Price per Item: $" << item1.getPricePerItem() << endl;

    double totalPrice = item1.calculateTotalPrice();
    cout << "Total Price: $" << totalPrice << endl;

    return 0;
}

