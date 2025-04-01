#include <iostream>
#include <cmath>
using namespace std;

class Animal {
    private:
        string name;
        int age;
    
    public: 
        Animal(string name, int age) {
            this->name = name;
            this->age = age;
        }
        
        string getName() const {
            return this->name;
        }

        void setName(string n) {
            this->name = n;
        }

        int getAge() const {
            return age;
        }
        
        void setAge(int a) {
            this->age = a;
        }

        virtual string sound() {
            return "";
        }
};

class Dog : public Animal {
    public:
        Dog(string n, int a): Animal(n, a) {}

        string sound() override {
            return "bark";
        }
};

class Cat : public Animal {
    public:
        Cat(string n, int a): Animal(n, a) {}

        string sound() override {
            return "meow";
        }
};

int main() {
    Animal an("animal", 1);
    Animal* dog = new Dog("James", 3);
    Animal* cat = new Cat("Patrick", 10);

    cout << an.sound() << endl;
    cout << dog->sound() << endl;
    cout << cat->sound() << endl;

    return 0;
}