## Class

```c++
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        name = n;
        age = a;
    }

    ~Student() {
        cout << "Destructor  works" << endl;
    }
    
    void talk() {
        cout << "Hello, my name is " << name << endl;
    }

    int getAge() {
        return age;
    }
};

int main() {
    Student student1("Parker", 20);

    student1.talk();

    return 0;
}
```

## This

```c++
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
```