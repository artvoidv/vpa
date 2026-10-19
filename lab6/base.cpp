#include <iostream>
#include <ctime>

#define SIZE 10

int
main()
{
    double sum = 0;
    double arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Введите число #" << (i+1) << ": ";
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода\n";
            return 0;
        }
        if (i%2 == 0) {
            sum += arr[i];
        }
    }
    std::cout << "сумма на четных индексах: " << sum << '\n';
    return 0;
}
