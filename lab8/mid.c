#include <stdio.h>
#include <stdlib.h>

#define STARTSIZE 64
#define isupper(c) ((c >= 'A') && (c <= 'Z'))
#define NOTWORD   0
#define SPACE     1
#define STARTWORD 2
#define INLWORD   3
#define INUWORD   4

int
main(void)
{
    size_t strsize, n;
    strsize = sizeof(char) * STARTSIZE;
    int uppercase_words = 0;
    n = 0;
    char* str = malloc(strsize);
    if (str == NULL) {
        fputs("allocation failed", stderr);
        return 1;
    }
    int c;
    int status = SPACE;
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
        if (c == ' ') {
            if (status == INUWORD) {
                uppercase_words++;
            }
            status = SPACE;
        } else {
            if (status == SPACE) {
                status = isupper(c) ? INUWORD: INLWORD;
            }
        }
    }
    if (status == INUWORD) {
        uppercase_words++;
    }
    str[n] = '\0';
#ifdef imstupid
    printf("%s\n---\n", str);
#endif
    printf("number of uppercase words: %d\n", uppercase_words);
    free(str);
    return 0;
}
