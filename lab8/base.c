#include <stdio.h>
#include <stdlib.h>

#define isnum(c) (((c) >= '0') && ((c) <= '9'))
#define STARTSIZE 64
#define NOTNUM 0
#define INNUM 1

int
main(void)
{
    int digits, numbers;
    size_t strsize, n;
    strsize = sizeof(char) * STARTSIZE;
    n = digits = numbers = 0;
    char* str = malloc(strsize);
    if (str == NULL) {
        fputs("allocation failed", stderr);
        return 1;
    }
    int c;
    int status = NOTNUM;
    while((c = getchar()) != '\n' && c != EOF) {
        n++;
        if (n + 1 >= (strsize/sizeof(char))) { /* n + 1 and >= because '\0' */
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
        if (isnum(c)) {
            digits++;
            status = INNUM;
        } else {
            if (status == INNUM) {
                numbers++;
                status = NOTNUM;
            }
        }
    }
    str[n] = '\0';
    if (status == INNUM) {
        numbers++;
    }
#ifdef imstupid
    printf("%s\n---\n", str);
#endif
    printf("Цифр: %d\nЧисел: %d\n", digits, numbers);
    free(str);
    return 0;
}
