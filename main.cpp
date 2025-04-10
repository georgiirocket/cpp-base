#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Lambda to print numbers
    auto print_number = [](int n) {
        std::cout << n << ' ';
    };

    for (int n : numbers) {
        print_number(n);
    }
    // Output: 1 2 3 4 5 

    return 0;
}