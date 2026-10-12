#include <iostream>

int main()
{
    double number;
#ifndef test
    std::cout << "Введите число: ";
#endif
    std::cin >> number;
    if (std::cin.fail()) {
        std::cout << "Ошибка ввода\n";
        return 1;
    }
    if (number < 0) {
        number *= -1;
    }
    std::cout << number << '\n';
    return 0;
}
