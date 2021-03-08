
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
	int i;
	unsigned int j;
	char *s = "pastel";

	i = -1542343;
	j = 4294967295 + i + 1;
	printf("Eu quero comer %u  \n", j);
	printf("Teste de novo %*p \n", 10, &i);
	printf("Mais teste %-*s \n", 16, s);
	passargs(5, "vou", "comer", s, 5, "testenovo");
	ft_printf("coxinha");
}
