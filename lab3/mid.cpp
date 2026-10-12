#include <iostream>
#include <utility>

int main()
{
    double numbers[3];
    for (int i = 0; i < 3; i++) {
#ifndef test
        std::cout << "Введите число №" << (i+1) << ": ";
#endif
        std::cin >> numbers[i];
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода";
            return 1;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = i+1; j < 3; j++) {
            if (numbers[j] < numbers[i]) {
                std::swap(numbers[j], numbers[i]);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n';
    return 0;
}
