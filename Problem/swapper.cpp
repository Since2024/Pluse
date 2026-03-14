#include <iostream>

// Using '&' allows us to modify the actual variables in main
void swapValues(int &x, int &y) {
    int temporary = x;
    x = y;
    y = temporary;
}

int main() {
    int walletA = 10;
    int walletB = 500;

    std::cout << "Before swap: A=" << walletA << ", B=" << walletB << std::endl;

    swapValues(walletA, walletB);

    std::cout << "After swap: A=" << walletA << ", B=" << walletB << std::endl;
    return 0;
}