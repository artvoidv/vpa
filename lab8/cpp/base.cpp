#include <iostream>
#include <string>
#include <cstdio>
#include <cstddef>

#define isnum(c) (((c) >= '0') && ((c) <= '9'))

int
main(void)
{
    int digits = 0;
    std::string s;
    if (!std::getline(std::cin, s, '\n')) {
        std::printf("err");
        return 1;
    }
    for (char c : s) {
        if (isnum(c)) digits++;
    }
    std::printf("digits in string: %d\n", digits);
    return 0;
}
