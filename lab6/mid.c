#include <unistd.h>

#define arrSIZE 20

int
main()
{
    char msg[] = "Сумма: 0\n";
    write(1, msg, sizeof msg);
    return 0;
}
