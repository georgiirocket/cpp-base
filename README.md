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

## Virtual, override

```c++
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
```

## Polymorphism

```c++
#include <iostream>
#include <cmath>
using namespace std;


class Shape {
    public:
        string color;

    virtual double calculateArea() {
        return 0.0;
    }    
};

class Circle : public Shape {
    public:
        int radius = 5; 

    double calculateArea() override {
        return 3.14 * pow(this->radius, 2);
    }       
};

class Rectangle : public Shape {
    public:
        int width = 2;
        int height = 3;

    double calculateArea() override {
        return this->width * this->height;
    }         
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    cout << shape1->calculateArea() << endl;

    return 0;
}
```

## Abstract class, clear virtual method

```c++
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
        virtual int calculateArea() = 0;
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
};

int main() {
    Circle c(10);
    Rectangle r(2,3);

    cout <<  c.calculateArea() << endl;
    cout <<  r.calculateArea() << endl;

    return 0;
}
```

## Interfaces

```c++
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
```

## Typeid info

```c++
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
```