#include <stdio.h>
#include <stdarg.h>

int sumints(int count, ...)
{
	va_list numbers;
	int sum = 1;
	va_start(numbers, count);
	while(count)
	{
		int arg = va_arg(numbers, int);
		printf("arg: %d\n", arg);
		sum *= arg;
		count--;
	}
	va_end(numbers);
	return sum;
}
#include <stdlib.h>	

int main(int av, char **ac)
{
	int i = av - 1;
	int j = 1; 
	int sumi = 1;
	while(j < i + 1)
	{
		sumi *= sumints(1, atoi(ac[j]));
		j++;
	}
	printf("sum: %d\n", sumi);
}