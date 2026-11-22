#include <iostream>
#include <string>

#define isupper(c) ((c >= 'A') && (c <= 'Z'))

int
main(void)
{
    int uppercase;
    std::string s;
    size_t i;

    if (!std::getline(std::cin, s, '\n')) {
        std::cout << "input error\n";
        return 1;
    }

    uppercase = 0;
    i = 0;
    for (; i < s.size(); ++i)
        if (isupper(s[i]))
            if (i-1 >= 0 && s[i-1] == ' ')
                ++uppercase;

    std::cout << uppercase << '\n';
    return 0;
}
