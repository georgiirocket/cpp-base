#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
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

    friend class Printer;
};

class Printer {
public:
    void print(const Person &p) {
        cout << p.name << " " << p.age << endl;
    }
};



int main() {
    Person person("Patrik", 10);

    Printer printer;
    printer.print(person);

    return 0;
}