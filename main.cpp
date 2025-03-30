#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    int getAge() const {
        return this->age;
    }

    void setAge(int age) {
        this->age = age;
    }
};

int main() {
    Person person("Patrik", 10);

    cout << person.getAge() << endl;
    
    person.setAge(15);

    cout << person.getAge() << endl;

    return 0;
}