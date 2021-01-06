#include <stdio.h>

int main(void)
{
	/*
	int a, b;

	while (scanf_s("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}
	*/

	int a, b;

	while (scanf_s("%d %d\n", &a, &b) == 2)
	{
		printf("%d\n", a + b);
	}
}