#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>

#ifndef arrSIZE
#define arrSIZE 20
#endif

int
main()
{
    int arr[arrSIZE];
    std::srand((unsigned)(std::time(NULL)) ^ getpid());
    for (int i = 0; i < arrSIZE; i++) {
        arr[i] = 1+(std::rand() % 100);
#ifdef test
        std::cout << arr[i] << ' ';
#endif
    }
    std::cout << '\n';
    for (int a = 0,b = arrSIZE-1; a < b; a++, b-=1) {
        if (arr[a] == arr[b]) {
            continue;
        } else {
            std::cout << "Массив не палиндром\n";
            return 1;
        }
    }
    std::cout << "Массив палиндром\n";
    return 0;
}
