#include <iostream>
#include <string>
using namespace std;

class A {
    public:
        A() {
            cout << "A created" << endl;
        }

        ~A() {
            cout << "A destroed" << endl;
        }

        weak_ptr<A> partner;
};



int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<A> b = make_shared<A>();

    a->partner = b;
    b->partner = a;

    return 0;
}