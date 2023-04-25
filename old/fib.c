#include <stdio.h>

int fib(int number)
{
	if (number <= 1)
		return number;
	return fib(number - 2) + fib(number - 1);
}

int main()
{
	printf("fib(5) = %d\n", fib(5));
	return 0;
}
