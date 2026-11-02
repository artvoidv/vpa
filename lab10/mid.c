#include <stdio.h>
#include <stdlib.h>

#define STARTSIZE 64

void
replaceChar(char *c, char a, char b)
{
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == a) c[i] = b;
    }
}

int
main(void)
{
    size_t strsize, n;
    n = 0;

    strsize = sizeof(char) * STARTSIZE;
    char* str = malloc(strsize);
    if (str == NULL) {
        fputs("allocation failed", stderr);
        return 1;
    }

    printf("Введите строку: ");
    int c;
    while((c = getchar()) != '\n' && c != EOF) {
        n++;
        if (n + 1 >= (strsize/sizeof(char))) {
            strsize *= 2;
            char* tmp = realloc(str, strsize);
            if (!tmp) {
                free(str);
                fputs("reallocation failed", stderr);
                return 1;
            }
            str = tmp;
        }
        str[n-1] = c;
    }
    str[n] = '\0';

    char a, b;
    printf("Введите символы для замены: ");
    int m = scanf("%c %c", &a, &b);
    if (m != 2) {
        fputs("Ошибка ввода", stderr); 
        return 1;
    }

    printf("Строка до изменений:\n%s\n", str);
    replaceChar(str, a, b);
    printf("Строка после изменений %c -> %c:\n%s\n", a,b,str);
    free(str);
    return 0;
}
