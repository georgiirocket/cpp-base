#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Min(T a, T b) {
    return a < b ? a : b;
}

int main() {
    cout << Min(10, 2) << endl;
    cout << Min('a', 'b') << endl;

    return 0;
}