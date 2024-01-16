#include <stdarg.h>
#include <stdio.h>

int max(int count, ...)
{
	va_list numbers;
	va_start(numbers, count);
	int max = va_arg(numbers, int);
	int num ;
	while(count)
	{
		num = va_arg(numbers, int);
		if (num > max)
			max = num;
		count--;
	}
	va_end(numbers);
	return max;
}
int min(int count, ...)
{
	va_list numbers;
	va_start(numbers, count);
	int min = va_arg(numbers, int);
	count--;
	int num ;
	while(count)
	{
		num = va_arg(numbers, int);
		if (num < min)
			min = num;
		count--;
	}
	va_end(numbers);
	return min;
}
int main()
{
	printf("max: %d\n", max(5, 1, 4, -1, 12314, -12));
	printf("min: %d\n", min(5, 1, 4, -1, 12314, -12));
}