#include <stdio.h>

int
isPalindrome(int a)
{
    int r = 0;
    int o = a;
    while (a > 0) {
        r = r*10 + a%10;
        a = a/10;
    }
    if (o == r) return 1;
    return 0;
}

int
isSPalindrome(int a)
{
    if (a < 0) a *= -1;
    return isPalindrome(a);
}

int
main(void)
{
    int a;
    printf("Введите число: ");
    int n = scanf("%d", &a);
    if (n != 1) {
        fputs("Ошибка ввода", stderr);
        return 1;
    }
    printf("Число %d - %sпалиндром\n", a, isPalindrome(a) ? "" : "не ");
    return 0;
}
