#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int b_t(int** map, int n, int m, int x[], int y[], int a, int b, int k)
{
	int i, j, k;
	int r1 = 0, r2 = 0;
	int a[3][3];

	if (k >= 3)
	{
		for (i = 0; i < 3; i++)
		{
			a[i][0] = 0;
		}

		while (1)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (map[i][j] == 1)
					{

						if (abs(x[0] - i) + abs(y[0] ))
					}
				}
			}
		}
		return 0;
	}
	else if (a >= (n + 1) || b >= n)
		return 0;

	if (a + 1 < (n + 1))
		r1 = b_t(map, n, m, x, y, a + 1, b, k);
	else
		r1 = b_t(map, n, m, x, y, 0, b + 1, k);

	if (map[a][b] != 1)
	{
		x[k] = a;
		y[k] = b;

		if(a + 1 < (n + 1))
			r1 = b_t(map, n, m, x, y, a + 1, b, k + 1);
		else
		r1 = b_t(map, n, m, x, y, 0, b + 1, k + 1);
	}
}

int main(void)
{
	int i, j;
	int n, m, d;
	int** map;

	scanf("%d %d %d", &n, &m, &d);

	map = (int**)malloc(sizeof(int*) * (n+1));
	for (i = 0; i < (n + 1); i++)
	{
		map[i] = (int*)malloc(sizeof(int) * m);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (j = 0; j < m; j++)
	{
		map[i][j] = 2;
	}


	for (i = 0; i < (n + 1); i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d", map[i][j]);
		}
	}
}