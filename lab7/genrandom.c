#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char *argv[])
{
    if (argc<3) {
        return 1;
    }
    int rows, cols;
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    srand((unsigned)time(NULL));
    for (int i = 0; i<rows*cols; i++) {
        printf("%d\n", -20 + rand()%41);
    }
    return 0;
}
