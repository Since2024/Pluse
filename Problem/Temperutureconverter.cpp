#include <iostream>

void toCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    std::cout << fahrenheit << "F is " << celsius << "C" << std::endl;
}

int main() {
    double temp;
    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> temp;

    toCelsius(temp); 

    return 0;
}