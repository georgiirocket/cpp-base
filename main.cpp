#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>
#include <vector>
using namespace std;

class Animal {
    protected:
        string name;
        int age;
        
    public:
        Animal(string name, int age) {
            this->name = name;
            this->age = age;
        }
        
        string getName() const {
            return name;
        }
        
        void setName(string name) {
            this->name = name;
        }
        
        int getAge() const {
            return age;
        }
        
        void setAge(int age) {
            this->age = age;
        }
        
        virtual string sound() = 0;

        virtual void info() = 0;
};
    
class Dog : public Animal {
    public:
        Dog(string name, int age) : Animal(name, age) {
            
        }
    
        string sound() override {
            return "bark";
        }

        void info() override {
            cout << "Dog" << endl;
            cout << "Name: " << this->getName() << endl;
            cout << "Age: " << this->getAge() << endl;
        }
};
    
class Cat : public Animal {
    public:
        Cat(string name, int age) : Animal(name, age) {
            
        }
    
        string sound() override {
            return "meow";
        }

        void info() override {
            cout << "Cat" << endl;
            cout << "Name: " << this->getName() << endl;
            cout << "Age: " << this->getAge() << endl;
        }
};

class AnimalShelter {
    private: 
        int room;
        vector<Animal*> storage = {};
    
    public:
        AnimalShelter(int room) {
            this->room = room;
        }
        
        void addAnimal(Animal* animal) {
            if(this->storage.size() == this->room) {
                return;
            }

            this->storage.push_back(animal);
        }

        void listAnimals() {
            for (int i = 0; i < this->storage.size(); i++) {
                this->storage[i]->info();
            }
        }
};

int main() {
    Cat cat("Mouse", 10);
    Dog dog("Patrik", 3);
    Dog dog1("Patrik_1", 9);
    Dog dog2("Kuku", 12);

    AnimalShelter st(3);

    st.addAnimal(&cat);
    st.addAnimal(&dog);
    st.addAnimal(&dog1);
    st.addAnimal(&dog2);

    st.listAnimals();

    return 0;
}