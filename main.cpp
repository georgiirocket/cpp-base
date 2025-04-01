#include <iostream>
#include <cmath>
using namespace std;


class Shape {
    private:
        string color;

    virtual double calculateArea() {
        return 0.0;
    }    
};

class Circle : public Shape {
    public:
        int radius; 

    double calculateArea() override {
        return 3.14 * pow(this->radius, 2);
    }       
};

class Rectangle : public Shape {
    public:
        int width;
        int height;

    double calculateArea() override {
        return this->width * this->height;
    }         
};

int main() {
    return 0;
}