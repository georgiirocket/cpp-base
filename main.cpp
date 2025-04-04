#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

template <>
char Max<char>(char a, char b) {
    return a > b ? toupper(a) : toupper(a);
}

int main() {
    cout << Max(10, 2) << endl;
    cout << Max('a', 'b') << endl;

    return 0;
}