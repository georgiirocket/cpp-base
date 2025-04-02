#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
        virtual int calculateArea() = 0;
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
};

int main() {
    Circle c(10);
    Rectangle r(2,3);

    cout <<  c.calculateArea() << endl;
    cout <<  r.calculateArea() << endl;

    return 0;
}