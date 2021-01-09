#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long sum(int*a, int n)
{
	long long ans = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		ans += a[i];
	}

	return ans;
}

int main(void)
{
	int * a[2];

	a[0] = 1;
	a[1] = 2;
	printf("%lld", sum(a, 2));
}