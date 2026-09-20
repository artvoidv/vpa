#include <iostream>

int main() {
    double input;
    double result;

    std::cout << "Введите x: ";
    std::cin >> input;

    if (std::cin.fail()) {
        std::cout << "Ошибка ввода" << "\n";
        return 0;
    }    
    
    result = input * input;
    
    std::cout.precision(10);
    std::cout << "Квадрат числа " << input << " равен " << result << "\n";

    return 0;
}
