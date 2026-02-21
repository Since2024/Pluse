#include <iostream>
#include <cmath>

double f(double x) { return x*x*x - x - 1; }

void secant(double x1, double x2, double tol) {
    double x3, f1, f2;
    do {
        f1 = f(x1);
        f2 = f(x2);
        x3 = x2 - (f2 * (x2 - x1)) / (f2 - f1);
        x1 = x2;
        x2 = x3;
    } while (std::abs(f(x3)) > tol);
    
    std::cout << "Root: " << x3 << std::endl;
}

int main() {
    secant(1, 2, 0.0001);
    return 0;
}
