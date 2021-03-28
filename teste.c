#include <stdio.h>
#include "ft_printf.h"
int main()
{
	printf("aqui = %010.0d", -129424);
	ft_printf("aqui = %010.0d", -129424);
}
