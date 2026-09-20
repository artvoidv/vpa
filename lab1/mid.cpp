#include <iostream>
#include <iomanip>

int main() {
    double input, squared, cubed;
    
    std::cout << "Введите x: ";
    std::cin >> input; 
   
    /* проверка на невереный ввод */
    if (std::cin.fail()) {
        /* выход из программы если ввод не верный */
        std::cout << "Ошибка ввода\n";
        return 0;
    }
    /* вычесление квадрата и куба числа */
    squared = input * input;
    cubed = input * input * input;

    /* установка точности и вывод результата */
    std::cout << std::setprecision(12) << "Квадрат числа " << input << " равен " << squared << "\nКуб числа " << input << " равен " << cubed << "\n";
    
    return 0;
}
