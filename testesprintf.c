
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
	char *d;

	d = "jfijlgk";
	c = "josenicacio";
	ft_printf("%.16s e %015u\n", c, -1513132);
	printf("%.16s e %015u", c, -1513132);
}
