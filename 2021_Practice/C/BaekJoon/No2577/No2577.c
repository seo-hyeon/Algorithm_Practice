#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int result, i;
	int l[10] = { 0 };

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	result = a * b * c;

	for (i = 0; result > 0; i++)
	{
		l[result % 10] += 1;
		result /= 10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", l[i]);
	}
}