#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int factor = 2;

    // Lambda capturing the 'factor' variable
    auto multiply_by_factor = [factor](int &n) {
        n *= factor;
    };

    for (int &n : numbers) {
        multiply_by_factor(n);
    }

    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';  // Output: 2 4 6 8 10

    return 0;
}