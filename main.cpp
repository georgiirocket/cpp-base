#include <iostream>
#include <cmath>
using namespace std;


class Shape {
    private:
        string color;
    public:
        Shape(string c) {
            color = c;
        }
        
        string info() {
            return "Color: " + color;
        }
        
        virtual int calculateArea() {
            return 0;
        }

        virtual int calculatePerimeter() {
            return 0;
        }
    };
    
class Circle : public Shape {
    private:
        int radius;
        
    public:
        Circle(string c, int r) : Shape(c) {
            radius = r;
        }
        
        int calculateArea() override {
            return 3.14 * radius * radius;
        }

        int calculatePerimeter() override {
            return 2 * 3.14 * this->radius;
        }
};
    
class Rectangle : public Shape {
    private:
        int a;
        int b;
        
    public:
        Rectangle(string c, int a, int b) : Shape(c) {
            this->a = a;
            this->b = b;
        }
        
        int calculateArea() override {
            return a * b;
        }

        int calculatePerimeter() override {
            return 2 * (this->a + this->b);
        }
};

int main() {
    Shape* circle = new Circle("Red", 20);
    Shape* rec = new Rectangle("Green", 2, 3);

    cout << circle->calculatePerimeter() << endl;
    cout << rec->calculatePerimeter() << endl;

    return 0;
}