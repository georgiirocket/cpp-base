#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 10, b = 0;

    try {
        if(b == 0) {
            throw runtime_error("Cannot divide by 0");
        }

        cout << a / b << endl;
    } catch(const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}