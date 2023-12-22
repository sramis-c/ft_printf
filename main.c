#include "ft_printf.h"
#include <limits.h>

int main()
{
    int a, b = 0;

    a = ft_printf("!% -45.23d!", 0);
    printf("\n");
    b = printf("!% -45.23d!", 0);

    printf("\nft:%d\n%d", a, b);
}