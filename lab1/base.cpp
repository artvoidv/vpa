#include <iostream>

int main() {
    // unsigned because -x * -x = x * x
    unsigned int inp;
    unsigned long long int res;

    std::cout << "Enter x: ";
    std::cin >> inp;
    
    res = inp * inp;
    std::cout << "\n" << inp << "^2 = " << res << "\n";

    return 0;
}
