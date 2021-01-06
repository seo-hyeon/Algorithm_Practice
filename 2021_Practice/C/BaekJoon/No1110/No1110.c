#include <stdio.h>

int main(void)
{
	int n, result, i = 0;

	scanf_s("%d", &n);
	result = n;

	do
	{
		result = (result % 10) * 10 + (result / 10 + result % 10) % 10;
		i++;
	} while (n != result);

	printf("%d", i);
}