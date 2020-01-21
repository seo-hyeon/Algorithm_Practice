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
int main(void)
{

}