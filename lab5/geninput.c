#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
    srand((unsigned)time(NULL) ^ (unsigned)getpid());
    printf("%d %d %d\n", -34000 - rand()%2001, 34000 + rand()%2001, 1 + rand()%20);
    return 0;
}
