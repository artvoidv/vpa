#include <stdio.h>
#include <stdlib.h>

#define isnum(c) (((c) >= '0') && ((c) <= '9'))
#define STARTSIZE 64
#define NOTNUM 0
#define INNUM 1

int
main(void)
{
    int bufnum = 0;
    size_t s, strsize, n, numsize;
    strsize = sizeof(char) * STARTSIZE;
    numsize = sizeof(int)  * STARTSIZE / 2;
    s = n = 0;
    char* str = malloc(strsize);
    if (str == NULL) {
        fputs("allocation failed", stderr);
        return 1;
    }
    int * nums= malloc(numsize);
    if (nums== NULL) {
        free(str);
        fputs("allocation failed", stderr);
        return 1;
    }
    int c;
    int status = NOTNUM;
    while((c = getchar()) != '\n' && c != EOF) {
        s++;
        if (s + 1 >= (strsize/sizeof(char))) { /* n + 1 and >= because '\0' */
            strsize *= 2;
            char* tmp = realloc(str, strsize);
            if (!tmp) {
                free(str);
                free(nums);
                fputs("reallocation failed", stderr);
                return 1;
            }
            str = tmp;
        }
        str[s-1] = c;
        if (isnum(c)) {
            bufnum = bufnum * 10 + (c - '0');
            status = INNUM;
        } else {
            if (status == INNUM) {
                status = NOTNUM;
                n++;
                if (n >= (numsize/sizeof(int))) {
                    numsize *= 2;
                    int* ntmp = realloc(nums, numsize + sizeof(int)); /* +sizeof(int) for possible trailing int after \n to avoid possible realloc at the end */
                    if (!ntmp) {
                        free(nums);
                        free(str);
                        fputs("realloc failed", stderr);
                        return 1;
                    }
                    nums = ntmp;
                }
                nums[n-1] = bufnum;
                bufnum = 0;
            }
        }
    }
    str[s] = '\0';
    if (status == INNUM) {
        nums[n++] = bufnum;
    }
#ifdef imstupid
    printf("%s\n---\n", str);
#endif
    for (size_t i = 0; i < n; i++) {
        printf(" %d ", nums[i]);
    }
    putchar('\n');
    free(str);
    free(nums);
    return 0;
}
