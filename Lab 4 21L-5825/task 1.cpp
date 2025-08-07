#include <iostream>

using namespace std;

class Triangle {
private:
    double length;
    double height;
    double width;

public:
    Triangle() {
        length = 0;
        height = 0;
        width = 0;
    }

    Triangle(double len, double ht, double wid) {
        length = len;
        height = ht;
        width = wid;
        cout << "Overloaded/parameterized Constructor Called" << endl;
    }

    ~Triangle() {
        cout << "Destructor Called" << endl;
    }

    void setLength(double len) {
        length = len;
    }

    void setHeight(double ht) {
        height = ht;
    }

    void setWidth(double wid) {
        width = wid;
    }

    double getLength() const {
        return length;
    }

    double getHeight() const {
        return height;
    }

    double getWidth() const {
        return width;
    }

    double calculateArea() const {
        return 0.5 * length * height;
    }

    double calculatePerimeter() const {
        return length + height + width;
    }

    static void printTriangleProperties() {
        double length = 3;
        double height = 4;
        double width = 5;
        Triangle triangle(length, height, width);
        double area = triangle.calculateArea();
        double perimeter = triangle.calculatePerimeter();
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
    }
};

int main() {
    Triangle triangle;

    triangle.setLength(3);
    triangle.setHeight(4);
    triangle.setWidth(5);

    double length = triangle.getLength();
    double height = triangle.getHeight();
    double width = triangle.getWidth();

    cout << "Length: " << length << endl;
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;

    Triangle::printTriangleProperties();

    return 0;
}

