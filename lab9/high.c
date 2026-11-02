#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char
getrandomchar()
{
    int r = rand() % 36; /* 26+10+1*/
    if (r <= 25) {
        return ((rand()%2) ? 'a' : 'A') + r;
    } else {
        return '0' + r - 26;
    }
}

char*
genpass(int lenght)
{
    char* p = malloc((lenght+1) * sizeof(char));
    if (p == NULL) return NULL;
    for (int i = 0; i < lenght; i++) {
        p[i] = getrandomchar();
    }
    p[lenght] = '\0';
    return p;
}

int
main(int argc, char* argv[])
{
    srand((unsigned)(time(NULL) ^ getpid()));
    int lenght;
    if (argc < 2) {
        printf("Введите длину пароля: ");
        int n = scanf("%d", &lenght);
        if (n != 1) {
            fputs("Ошибка ввода", stderr);
            return 1;
        }
    } else {
        char* e = NULL;
        lenght = (int) strtol(argv[1], &e, 10);
    }
    char* pass = genpass(lenght);
    if (pass == NULL) {
        fputs("Ошибка алокации", stderr);
        return 1;
    }
    printf("Случайный пароль %d длинны: %s\n", lenght, pass);
    free(pass);
    return 0;
}
