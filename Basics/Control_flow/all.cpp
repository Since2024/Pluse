#include <iostream>
#include <vector>

int main() {
    // For loop example (prints 1 to 5)
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // While loop example (prints 0, 2, 4, 6, 8)
    int j = 0;
    while (j < 10) {
        std::cout << j << " ";
        j += 2;
    }
    std::cout << std::endl;

    // Do-while loop example (prints 0 at least once)
    int k = 0;
    do {
        std::cout << k << " ";
        k++;
    } while (k < 0); // Condition is false, but runs once
    std::cout << std::endl;

    // Range-based for loop example
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
