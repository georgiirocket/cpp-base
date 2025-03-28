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