#include <iostream>

int main()
{
    long long sum = 0;
    double multiplier = 1.0;
    unsigned char status = 0;
#ifndef test
    std::cout << "Введите сумму покупки: ";
#endif
    std::cin >> sum;
    if (std::cin.fail()) {
        std::cout << "Ошибка ввода";
        return 1;
    }
#ifndef test
    std::cout << "Введите статус (0 - обычный, 1 - VIP, 2 - сотрудник): ";
#endif
    std::cin >> status;
    if (status == '2') {
        multiplier -= 0.2;
    } else if (status == '1') {
        multiplier -= 0.1;
    }
    if (sum > 5000) {
        multiplier -= 0.05;
    }
    sum = sum * multiplier;
    std::cout << "Итоговая сумма: " << sum << '\n';
    return 0;
}
