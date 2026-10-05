#include <iostream>

int main()
{
    double sides[3];
    double volume = 1.0;
    for (int i = 0; i < 3; i++) {
#ifndef test
        std::cout << "Введите сторону #" << (i+1) << " параллелепипеда: ";
#endif
        std::cin >> sides[i];
        if (std::cin.fail() || sides[i] == 0.0) {
            std::cout << "Ошибка ввода\n";
            return 0;
        }
        volume = volume * sides[i];
    }

    std::cout << "Объем параллелепипеда: " << volume << "\n";
    std::cout << "Площадь параллелепипеда: " << static_cast<double>(2) * (sides[0] * sides[1] + sides[1] * sides[2] + sides[0] * sides[2]) << "\n";
    return 0;
}
