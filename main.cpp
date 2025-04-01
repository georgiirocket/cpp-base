#include <iostream>
#include <cmath>
using namespace std;

class Shape {
private:
    string color;

public:
    Shape(string c) {
        this->color = c;
    }  

    string info() {
        return "Color: " + this->color;
    }
};


class Circle : public Shape {
private: 
    int radius;

public:
    Circle(string color, int radius) : Shape(color) {
        this->radius = radius;
    }

    int calculateArea() {
        return 3.14 * pow(this->radius, 2);
    }    
};

class Rectangle: public Shape {
private:
    int a;
    int b;

public:    
    Rectangle(string color, int a, int b) : Shape(color) {
        this->a = a;
        this->b = b;
    }

    int calculateArea() {
        return this->a * this->b;
    }
};

int main() {
    Rectangle r("Red", 10, 12);
    Circle c("Green", 20);

    cout << r.calculateArea() << endl;
    cout << c.calculateArea() << endl;

    return 0;
}