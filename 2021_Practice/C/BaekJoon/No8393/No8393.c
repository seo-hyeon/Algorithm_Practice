#include <stdio.h>

int cal(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n + cal(n - 1);
	}
}

int main(void)
{
	int n, i, result = 0;

	scanf("%d", &n);

	/*
	for (i = 1; i <= n; i++)
	{
		result += i;
	}

	printf("%d", result);
	*/

	printf("%d", cal(n));
}