#include <stdio.h>
#include "ft_printf.h"
int main()
{
	printf("%d \n", printf("%c %c \n", 0, 0));
	printf("%d \n", ft_printf("%c %c \n", 0, 0));
}
