#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double legs[2] = {0};
    double hypotenuse;
    
    /* ввод значений катетов и проверка на неверный ввод*/
    for (int i = 0; i < 2; i++) {
        std::cout << "Введите катет №" << (i) << ": ";
        std::cin >> legs[i];
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода\n";
            return 0;
        }
    }
    
    /* вычесление промежуточного значения гипотенузы */
    hypotenuse = std::sqrt(std::pow(legs[0], 2) + std::pow(legs[1], 2));
    
    std::cout << std::setprecision(12) << "Гипотенуза треугольника: " << hypotenuse
    /* вычесление и вывод данных */
    << "\nПлощадь треугольника: " << (legs[0] * legs[1]) / static_cast<double>(2) << "\nПериметр треугольника: " << hypotenuse + legs[0] + legs[1] << "\n";

    return 0;
}
