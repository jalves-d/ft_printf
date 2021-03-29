#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int i;
	i = printf(" -%*c* -%-*c* \n", -2, 0, 2, 0);
	printf("%d \n", i);
	i = ft_printf(" -%*c* -%-*c* \n", -2, 0, 2, 0);
	printf("%d \n", i);
	/*	printf(" -%-*c* -%-*c* ", 2, 0, -2, 0);
	printf(" -%*c* -%-*c* ", -1, 0, 1, 0);
	printf(" -%-*c* -%-*c* ", 2, 0, -2, 0);
	printf(" -%-2c* -%2c* ", 0, 0);
*/
}
