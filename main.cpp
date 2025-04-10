#include <iostream>

int main() {
    int x = 10;

    auto increment = [x]() mutable {
        x++;
        std::cout << x << '\n';  // Output: 11
    };

    increment();
    std::cout << x << '\n';  // Output: 10

    return 0;
}