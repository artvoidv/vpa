#include <iostream>

int main()
{
    long long int kilometers;
#ifndef test
    std::cout << "Введите километры: ";
#endif
    std::cin >> kilometers;
    std::cout << kilometers << " километров = " << kilometers * 1000 << " метров\n";
    return 0;
}
