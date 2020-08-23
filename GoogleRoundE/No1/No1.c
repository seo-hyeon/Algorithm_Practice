#include <stdio.h>

int main(void)
{
	int t, n;
	int i, j, max, d, k;
	int *ans, *num;

	scanf("%d", &t);
	ans = (int *)malloc(sizeof(int) * t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);

		num = (int*)malloc(sizeof(int) * n);
		for (j = 0; j < n; j++)
			scanf("%d", &num[j]);

		max = -1;
		d = num[1] - num[0];
		k = 0;

		for (j = 1; j < n; j++)
		{
			if (num[j] - num[j - 1] == d)
			{
				k++;

				if (k > max)
					max = k;
			}
			else
			{
				d = num[j] - num[j - 1];
				k = 1;
			}
		}

		if (k > max)
			max = k;

		ans[i] = max + 1;
	}

	for (i = 0; i < t; i++)
	{
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
}