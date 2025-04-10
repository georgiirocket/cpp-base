#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

int main() {
    std::vector<int> numbers = {1, 5, 3, 4, 2};

    // Lambda for custom sorting in descending order
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return b < a;
    });

    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';  // Output: 5 4 3 2 1

    return 0;
}