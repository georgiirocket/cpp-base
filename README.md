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

## Friend function

```c++
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

    friend void print(const Person &p);
};

void print(const Person &p) {
    cout << p.name << " " << p.age << endl;
}

int main() {
    Person person("Patrik", 10);

    print(person);

    return 0;
}
```

## Friend class

```c++
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
```

## Static methods

```c++
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;
public:
    Counter() {
        count++;
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;



int main() {
    Counter c1;
    

    cout << c1.getCount() << endl;
    Counter c2;

    cout << c2.getCount() << endl;

    return 0;
}
```

## Inline varible

```c++
#include <iostream>
using namespace std;

class Item {
private:
    static inline int count = 0;
    int id;

public:
    Item() {
        count++;
        this->id = count;
    }

    static int getCount() {
        return count;
    }

    int getId() const {
        return this->id;
    }
};

int main() {
    for(int i = 0; i < 5; i++) {
        Item item;

        cout << "Id: " << item.getId() << endl;
        cout << "Count: " << item.getCount() << endl;
    }

    return 0;
}
```

## Enum

```c++
#include <iostream>
using namespace std;

enum Day {
    Sunday,
    Monday
};

int main() {
    Day one = Sunday;

    cout << one << endl;

    return 0;
}
```

## Class extends

```c++
#include <iostream>
using namespace std;

class Shape {
public:
    string color;

    Shape(string color) {
        this->color = color;
    }

    ~Shape() {
        cout << "Descructor shape" << endl;
    }
    
    void info() {
        cout << "Color: " << color << endl;
    }
};

//public Shape, protected Shape, privat shape
class Circle : public Shape {
public: 
    int radius;

    Circle(string color, int radius) : Shape(color) {
        this->radius = radius;
    }

    ~Circle() {
        cout << "Descructor circle" << endl;
    }

    void print() {
        this->info();
        cout << "Radius: " << this->radius << endl;
    }
};

int main() {
    Circle c("red", 10);

    c.print();
    return 0;
}
```