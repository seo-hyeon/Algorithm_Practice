#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, i, k;
	int min = 10000000, max = -10000000;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);

		if (max < k)
		{
			max = k;
		}
		
		if (min > k)
		{
			min = k;
		}
	}

	printf("%d %d", min, max);
}