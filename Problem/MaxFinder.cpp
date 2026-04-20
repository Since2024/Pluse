#include <iostream>

int findMax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a = 45, b = 82;
    
    int highest = findMax(a, b);
    
    std::cout << "The higher number is: " << highest << std::endl;
    return 0;
}