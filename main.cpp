#include <iostream>
#include <string>
using namespace std;

template <typename F, typename S>
struct Pair
{
    F first;
    S second;
};

template <typename F, typename S>
ostream& operator<<(ostream& out, const Pair<F, S>& p) {
    out << p.first << " " << p.second;

    return out;
}

int main() {
    Pair<string, int> p = {"Test", 20};

    cout << p << endl;

    return 0;
}