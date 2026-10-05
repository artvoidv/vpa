#include <iostream>

int main()
{
    double numbers[2];

    for (int i = 0; i < 2; i++) {
#ifndef test
        std::cout << "Введите число: ";
#endif
        std::cin >> numbers[i];
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода\n";
            return 0;
        }
    }

    std::cout.precision(10);
    std::cout << "Сумма int: " << static_cast<int>(numbers[0]) + static_cast<int>(numbers[1]) << "\tСумма double: " << numbers[0] + numbers[1] << "\n"; 
    std::cout << "Разность int: " << static_cast<int>(numbers[0]) - static_cast<int>(numbers[1]) << "\tРазность double: " << numbers[0] - numbers[1] << "\n"; 
    std::cout << "Произведение int: " << static_cast<int>(numbers[0]) * static_cast<int>(numbers[1]) << "\tПроизведение double: " << numbers[0] * numbers[1] << "\n"; 
    if (numbers[1] == 0.0) {
        std::cout << "Частное int: деление на ноль\tЧастное double: деление на ноль\n";
        return 0;
    }
    if (static_cast<int>(numbers[1]) == 0) {
        std::cout << "Частное int: деление на ноль";  
    } else {
        std::cout << "Частное int: " << static_cast<int>(numbers[0]) / static_cast<int>(numbers[1]);
    }
    std::cout << "\tЧастное double: " << numbers[0] / numbers[1] << "\n"; 
    return 0;
}
