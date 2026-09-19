#include <iostream>

int main() {
    long int inp;
    long long int cubed;
    long long int squared;
    
    std::cout << "Enter x: ";
    std::cin >> inp;
    
    squared = inp * inp;
    cubed = inp * inp * inp;
    
    std::cout << "\nX^2 = " << squared << "\nX^3 = " << cubed << "\n";
    
    return 0;
}
