//น้มุ 1094น๘ https://www.acmicpc.net/problem/1094

#include <stdio.h>
int main(void)
{
	int x;
	int n = 64, small, result = 1;

	scanf("%d", &x);

	small = n;
	while (x != n)
	{
		small /= 2;

		if (x <= n - small)
		{
			n -= small;
		}
		else
		{
			result++;
		}
	}

	printf("%d", result);
}