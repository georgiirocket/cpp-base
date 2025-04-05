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
};



int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<A> b = a;

    return 0;
}