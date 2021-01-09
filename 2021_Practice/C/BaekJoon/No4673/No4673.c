#include <stdio.h>
#include <stdlib.h>

int self(int n)
{
	int result = n;

	while (n > 0)
	{
		result += (n % 10);
		n /= 10;
	}

	return result;
}

int reverse_self(int n)
{
	int i;

	for (i = n - 1; i >= 1; i--)
	{
		if (self(i) == n)
		{
			return 1;
		}
	}

	return 0;
}
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (reverse_self(i) == 0)
		{
			printf("%d\n", i);
		}
	}
}