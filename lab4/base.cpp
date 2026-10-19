#include <iostream>

int
main()
{
    unsigned char direction = 1;
    switch (direction) {
        case 1: { std::cout << "Север\n"; break; }
        case 2: { std::cout << "Юг\n"; break; }
        case 3: { std::cout << "Запад\n"; break; }
        case 4: { std::cout << "Восток\n"; break; }
        default: { std::cout << "число за пределами определения\n"; break; }
    }
    return 0;
}
