#include <iostream>
#include <cmath>

int main() {
    double leg1 = 0.0;
    double leg2 = 0.0;

    std::cout << "Enter first leg: ";
    std::cin >> leg1;
    std::cout << "Enter second leg: ";
    std::cin >> leg2;

    std::cout << "Area: " << leg1 * leg2 / static_cast<double>(2) << "\nPerimeter: " << leg1 + leg2 + std::sqrt(std::pow(leg1, 2) + std::pow(leg2, 2)) << "\n";

    return 0;
}
