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
    unique_ptr<A> a = make_unique<A>();
    
    //Owner will be b;
    unique_ptr<A> b = move(a);

    return 0;
}