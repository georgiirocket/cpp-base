#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class Shape {
    public:
        virtual int calculateArea() = 0;
        virtual int calculatePerimeter() = 0;
        virtual string getTypeName() = 0;
};
    
class Circle : public Shape {
    private:
        int radius;
        
    public:
        Circle(int r) {
            radius = r;
        }
        
        int calculateArea() override {
            return 3.14 * radius * radius;
        }
        
        int calculatePerimeter() override {
            return 2 * 3.14 * radius;
        }
        
        string getTypeName() override {
            return typeid(*this).name();
        }
};
    
class Rectangle : public Shape {
    private:
        int a;
        int b;
        
    public:
        Rectangle(int a, int b) {
            this->a = a;
            this->b = b;
        }
        
        int calculateArea() override {
            return a * b;
        }
        
        int calculatePerimeter() override {
            return (a + b) * 2;
        }

        string getTypeName() override {
            return typeid(*this).name();
        }
    };
    
bool isCircle(Shape* shape) {
    const string str = "Circle";

    if(shape->getTypeName().find(str) != std::string::npos) {
        return true;
    }

    return false;
};

int main() {
    Shape* c = new Circle(10);
    Shape* r = new Rectangle(10, 5);
    
    cout << isCircle(c) << endl;
    cout << isCircle(r) << endl;


    return 0;
}