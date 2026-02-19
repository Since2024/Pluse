#include <iostream>

double f(double x) { return x*x*x - x - 2; } // Example: x^3 - x - 2 = 0

void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        std::cout << "Invalid interval [a, b]";
        return;
    }
    double c = a;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    std::cout << "Root: " << c << std::endl;
}

int main() {
    bisection(1, 2, 0.001);
    return 0;
}