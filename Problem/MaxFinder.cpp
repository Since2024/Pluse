#include <iostream>

// This function returns an 'int'
int findMax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a = 45, b = 82;
    
    // We 'catch' the returned value in a variable
    int highest = findMax(a, b);
    
    std::cout << "The higher number is: " << highest << std::endl;
    return 0;
}