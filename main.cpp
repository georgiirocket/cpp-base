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
};

class Dog : public Animal {
    public:
        Dog(string n, int a): Animal(n, a) {}
        
        string bark() {
            return "bark";
        }
};

class Cat : public Animal {
    public:
        Cat(string n, int a): Animal(n, a) {}
        
        string meow() {
            return "meow";
        }
};

int main() {
    Animal a("animal", 1);
    Dog d("Patric", 10);
    Cat c("Mouse", 3);

    cout << d.getName() << " " << d.getAge() << " " << d.bark() << endl;
    cout << c.getName() << " " << c.getAge() << " " << c.meow() << endl;

    return 0;
}