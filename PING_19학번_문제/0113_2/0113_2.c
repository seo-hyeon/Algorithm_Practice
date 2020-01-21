//น้มุ 3055น๘ https://www.acmicpc.net/problem/3055
#include <stdio.h>
#include <stdlib.h>
void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n' && ch != ' ') {};
}
void printMatrix(char **arr, int height, int width) {
	int i, j;

	printf("\n*****************************\n");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			printf("%3c", arr[i][j]);
		printf("\n");
	}
}
int other(char **arr, int x, int y)
{
	if (arr[x][y] == 'D' || arr[x][y] == '*' || arr[x][y] == 'X')
		return -1;
	else
		return 0;
}
char water(char **arr, int height, int width)
{
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (arr[i][j] == '*')
			{
				if (i > 0 && other(arr, i - 1, j) != -1)
					arr[i - 1][j] = '@';
				if (i < height - 1 && other(arr, i + 1, j) != -1)
					arr[i + 1][j] = '@';
				if (j > 0 && other(arr, i, j - 1) != -1)
					arr[i][j - 1] = '@';
				if (j < width - 1 && other(arr, i, j + 1) != -1)
					arr[i][j + 1] = '@';
			}
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (arr[i][j] == '@')
			{
				arr[i][j] = '*';
			}
		}
	}
}
int play(char** arr, int height, int width, int x, int y)
{
	int result = 100000, n, i, j;
	char** copy;

	if (arr[x][y] == 'D')
		return 0;

	if (other(arr, x, y) == -1)
	{
		//printf("\n**%d %d**\n", x, y);
		return 100000;
	}

	copy = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		copy[i] = (char*)malloc(sizeof(char) * width);

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			copy[i][j] = arr[i][j];

	//printf("%d %d", x, y);
	water(copy, height, width);
	//printMatrix(arr, height, width);

	if (x > 0)
		result = play(copy, height, width, x - 1, y) + 1;
	if ((x + 1) < height)
	{
		n = play(copy, height, width, x + 1, y) + 1;
		if (n < result)
			result = n;
	}
	if ((y - 1) >= 0)
	{
		n = play(copy, height, width, x, y - 1) + 1;
		if (n < result)
			result = n;
	}
	if ((y + 1) < width)
	{
		n = play(copy, height, width, x, y + 1) + 1;
		if (n < result)
			result = n;
	}

	for (i = 0; i < height; i++)
		free(copy[i]);
	free(copy);

	return result;
}
int main(void)
{
	int width, height, i, j, result;
	int sIndexX, sIndexY;
	char **arr;

	scanf("%d %d", &height, &width);

	arr = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		arr[i] = (char*)malloc(sizeof(char) * width);

	for (i = 0; i < height; i++)
	{
		clear_stdin();

		for (j = 0; j < width; j++)
		{
			scanf("%c", &arr[i][j]);

			if (arr[i][j] == 'S')
			{
				sIndexX = i;
				sIndexY = j;
			}
		}
	}
	//printMatrix(arr, height, width);

	result = play(arr, height, width, sIndexX, sIndexY);

	if (result >= 100000)
		printf("KAKTUS");
	else
		printf("%d", result);

	for (i = 0; i < height; i++)
		free(arr[i]);
	free(arr);
}





/*
#include <stdio.h>
#include <stdlib.h>
void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n' && ch != ' ') {};
}
void printMatrix(char **arr, int height, int width) {
	int i, j;

	printf("\n*****************************\n");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			printf("%3c", arr[i][j]);
		printf("\n");
	}
}
int other(char **arr, int x, int y)
{
	if (arr[x][y] == 'D' || arr[x][y] == '*' || arr[x][y] == 'X')
		return -1;
	else
		return 0;
}
char water(char **arr, int height, int width)
{
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (arr[i][j] == '*')
			{
				if (i > 0 && other(arr, i - 1, j) != -1)
					arr[i - 1][j] = '@';
				if (i < height - 1 && other(arr, i + 1, j) != -1)
					arr[i + 1][j] = '@';
				if (j > 0 && other(arr, i, j - 1) != -1)
					arr[i][j - 1] = '@';
				if (j < width - 1 && other(arr, i, j + 1) != -1)
					arr[i][j + 1] = '@';
			}
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (arr[i][j] == '@')
			{
				arr[i][j] = '*';
			}
		}
	}
}
int play(char** arr, int height, int width, int x, int y)
{
	int result = 100000, n, i, j;
	char** copy;

	if (arr[x][y] == 'D')
		return 0;

	if (other(arr, x, y) == -1)
	{
		//printf("\n**%d %d**\n", x, y);
		return 100000;
	}

	copy = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		copy[i] = (char*)malloc(sizeof(char) * width);

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			copy[i][j] = arr[i][j];

	//printf("%d %d", x, y);
	water(copy, height, width);
	//printMatrix(arr, height, width);

	if (x > 0)
		result = play(copy, height, width, x - 1, y) + 1;
	if ((x + 1) < height)
	{
		n = play(copy, height, width, x + 1, y) + 1;
		if (n < result)
			result = n;
	}
	if ((y - 1) >= 0)
	{
		n = play(copy, height, width, x, y - 1) + 1;
		if (n < result)
			result = n;
	}
	if ((y + 1) < width)
	{
		n = play(copy, height, width, x, y + 1) + 1;
		if (n < result)
			result = n;
	}

	for (i = 0; i < height; i++)
		free(copy[i]);
	free(copy);

	return result;
}
int main(void)
{
	int width, height, i, j, result;
	int sIndexX, sIndexY;
	char **arr;

	scanf("%d %d", &height, &width);

	arr = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		arr[i] = (char*)malloc(sizeof(char) * width);

	for (i = 0; i < height; i++)
	{
		clear_stdin();

		for (j = 0; j < width; j++)
		{
			scanf("%c", &arr[i][j]);

			if (arr[i][j] == 'S')
			{
				sIndexX = i;
				sIndexY = j;
			}
		}
	}
	//printMatrix(arr, height, width);

	result = play(arr, height, width, sIndexX, sIndexY);

	if (result >= 100000)
		printf("KAKTUS");
	else
		printf("%d", result);

	for (i = 0; i < height; i++)
		free(arr[i]);
	free(arr);
}
*/