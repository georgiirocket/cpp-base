#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class Animal {
    public: 
        virtual void print() {
            cout << "Object type: " << typeid(*this).name() << endl;
        }
};

class Dog : public Animal {};
class Cat : public Animal {};

int main() {
    Animal* d = new Dog;
    Animal* c = new Cat;

    d->print();
    c->print();

    return 0;
}