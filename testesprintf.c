
#include "printf.h"

void printargs(va_list list, int n)
{
	while(n > 0)
	{
		printf("%s\n", va_arg(list, char*));
		n--;
	}
}

void passargs(int n, ...)
{
	va_list list;

	va_start(list, n);
	printargs(list, 3);
	va_arg(list, int);
	printargs(list, 1);
	va_end(list);
}

int main(){
	char *c;

	c = "josenicacio";
	ft_printf("%8.5d \n", 123);
	printf("%8.5d", 123);
}
