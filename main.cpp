#include <iostream>
#include <cmath>
using namespace std;


class Shape {
    public:
        string color;

    virtual double calculateArea() {
        return 0.0;
    }    
};

class Circle : public Shape {
    public:
        int radius = 5; 

    double calculateArea() override {
        return 3.14 * pow(this->radius, 2);
    }       
};

class Rectangle : public Shape {
    public:
        int width = 2;
        int height = 3;

    double calculateArea() override {
        return this->width * this->height;
    }         
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    cout << shape1->calculateArea() << endl;

    return 0;
}