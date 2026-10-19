#include <iostream>

int
main()
{
    char charctr = '-';
    if (charctr >= 'A' && charctr <= 'Z') {
        charctr = charctr + ('a'-'A');
    }
    std::cout << "символ: ";
    switch(charctr) {
        case 'a': case 'i': case 'u': case 'o': case 'e': {
            std::cout << "Гласная буква\n";
            break;
        }
        default: {
            if (charctr >= 'a' && charctr <= 'z') {
                std::cout << "Согласная буква\n";
                break;
            }
            if (charctr >= '0' && charctr <= '9') {
                std::cout << "Цифра\n";
                break;
            }
            std::cout << "Другой символ\n";
            break;
        }
    }
    return 0;
}
