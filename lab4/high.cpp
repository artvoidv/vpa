#include <iostream>

int
main()
{
    int lesson = 0;
    std::cout << "Введите номер урока: ";
    std::cin >> lesson;
    if (std::cin.fail()) {
        std::cout << "Ошибка ввода\n";
        return 1;
    }
    std::cout << "Урок #" << lesson << ": ";
    switch(lesson) {
        case 1: {
            std::cout << "8:00 - 8:45\n";
            break;
        }
        case 2: {
            std::cout << "8:55 - 9:40\n";
            break;
        }
        case 3: {
            std::cout << "9:50 - 10:35\n";
            break;
        }
        case 4: {
            std::cout << "10:55 - 11:40\n";
            break;
        }
        case 5: {
            std::cout << "11:50 - 12:35\n";
            break;
        }
        case 6: {
            std::cout << "12:45 - 13:30\n";
            break;
        }
        case 7: {
            std::cout << "13:40 - 14:25\n";
            break;
        }
        case 8: {
            std::cout << "14:35 - 15:20\n";
            break;
        }
        default: {
            std::cout << "Неверный номер урока\n";
            break;
        }
    }
    return 0;
}
