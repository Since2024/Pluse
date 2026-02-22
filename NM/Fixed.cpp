#include <iostream>
#include <cmath>

// Example: f(x) = x^2 - x - 1 = 0  => x = sqrt(x + 1)
double g(double x) { return sqrt(x + 1); } 

void fixedPoint(double x0, double tol) {
    double x1;
    int iter = 0;
    do {
        x1 = g(x0);
        if(std::abs(x1 - x0) < tol) break;
        x0 = x1;
    } while (++iter < 100);
    
    std::cout << "Root: " << x1 << " (Found in " << iter << " iterations)" << std::endl;
}

int main() {
    fixedPoint(1.0, 0.0001);
    return 0;
}