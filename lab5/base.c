#include <stdio.h>

int
main()
{
    int start = 10, end = 44, jump = 5;
    printf("y=(x-2)^2\n");
    printf("%4c | %c\n", 'x', 'y');
    for (int i = start; i < end; i+=jump) {
        printf("%4d | %d\n", i, (i-2) * (i-2));
    }
    return 0;
}
