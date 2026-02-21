#include <iostream>
#include <cmath>

double f(double x) { return x*x - 4; }   // Function
double df(double x) { return 2*x; }     // Derivative

void newtonRaphson(double x0, double tol) {
    double h = f(x0) / df(x0);
    while (std::abs(h) >= tol) {
        h = f(x0) / df(x0);
        x0 = x0 - h;
    }
    std::cout << "Root: " << x0 << std::endl;
}

int main() {
    newtonRaphson(3, 0.001); // Initial guess 3
    return 0;
}
