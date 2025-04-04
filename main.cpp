#include <iostream>
#include <string>
using namespace std;

template<typename T>

T Max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    cout << Max(5, 6) << endl;
    cout << Max(5.25, 5.27) << endl;

    return 0;
}