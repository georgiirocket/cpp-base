#include <iostream>
using namespace std;

class Shape {
public:
    string color;

    Shape(string color) {
        this->color = color;
    }

    ~Shape() {
        cout << "Descructor shape" << endl;
    }
    
    void info() {
        cout << "Color: " << color << endl;
    }
};

//public Shape, protected Shape, privat shape
class Circle : public Shape {
public: 
    int radius;

    Circle(string color, int radius) : Shape(color) {
        this->radius = radius;
    }

    ~Circle() {
        cout << "Descructor circle" << endl;
    }

    void print() {
        this->info();
        cout << "Radius: " << this->radius << endl;
    }
};

int main() {
    Circle c("red", 10);

    c.print();
    return 0;
}