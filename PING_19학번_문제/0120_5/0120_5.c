//น้มุ 2992น๘ https://www.acmicpc.net/problem/2992

#include <stdio.h>
int main(void)
{
	int n, i, j, size;
	int num[50];
	int max;

	scanf("%d", &n);

	for (i = 0; n / 10 != 0; n /= 10, i++)
	{
		num[i] = n % 10;
	}
	num[i] = n;

	size = i;

	j = 0;

	for (i = 1; i <= size; i++)
	{
		if (num[i-1] > num[i])
		{
			max = num[i - 1];
			num[i - 1] = num[i];
			num[i] = max;
			j = 1;
			break;
		}
	}

	if (j == 1)
	{
		for (i = size; i >= 0; i--)
			printf("%d", num[i]);
	}
	else
		printf("0");
}