#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int b_t(int** map, int n, int x, int y, int k)
{
	int i;
	int r1 = 0, r2 = 0, r3 = 0;

	if (x >= n - 1 && y >= n - 1)
	{
		//printf("%d %d %d\n", x, y, k);
		return 1;
	}

	if (k == 1)
	{
		if(y + 1 < n && map[x][y + 1] != 1)
			r1 = b_t(map, n, x, y + 1, 1);
		if (x + 1 < n && y + 1 < n && map[x + 1][y] != 1 && map[x][y + 1] != 1 && map[x + 1][y + 1] != 1)
			r2 = b_t(map, n, x + 1, y + 1, 3);

		//printf("%d %d %d %d\n", x, y, k, r1 + r2);
		return r1 + r2;
	}
	else if (k == 2)
	{
		if (x + 1 < n && map[x + 1][y] != 1)
			r1 = b_t(map, n, x + 1, y, 2);
		if (x + 1 < n && y + 1 < n && map[x + 1][y] != 1 && map[x][y + 1] != 1 && map[x + 1][y + 1] != 1)
			r2 = b_t(map, n, x + 1, y + 1, 3);

		//printf("%d %d %d %d\n", x, y, k, r1 + r2);
		return r1 + r2;
	}
	else
	{
		if (x + 1 < n && map[x + 1][y] != 1)
			r1 = b_t(map, n, x + 1, y, 2);
		if (y + 1 < n && map[x][y + 1] != 1)
			r2 = b_t(map, n, x, y + 1, 1);
		if (x + 1 < n && y + 1 < n && map[x + 1][y] != 1 && map[x][y + 1] != 1 && map[x + 1][y + 1] != 1)
			r3 = b_t(map, n, x + 1, y + 1, 3);

		//printf("%d %d %d %d\n", x, y, k, r1 + r2 + r3);
		return r1 + r2 + r3;
	}
}

int main(void)
{
	int n, i,j;
	int** map;

	scanf("%d", &n);

	map = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * n);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d", b_t(map, n, 0, 1, 1));
}