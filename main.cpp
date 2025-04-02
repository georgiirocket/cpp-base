#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
        virtual int calculateArea() = 0;
        virtual void info() = 0;
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

        void info() override {
            cout << "Radius: " << this->radius << endl;
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

        void info() override {
            cout << "A: " << this->a << endl;
            cout << "B: " << this->b << endl;
        }
};

int main() {
    Circle c(10);
    Rectangle r(2,3);

    cout <<  c.calculateArea() << endl;
    cout <<  r.calculateArea() << endl;

    c.info();
    r.info();

    return 0;
}