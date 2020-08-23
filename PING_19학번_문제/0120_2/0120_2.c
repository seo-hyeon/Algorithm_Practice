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
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}
int play(char** arr, int** answer, int height, int width, int x, int y, int s)
{
	int result = -1, n, i, j;

	if (arr[x][y] == 'D')
		return 0;

	if (arr[x][y] != '.' && arr[x][y] != 'S' && s != 0 && answer[x][y] == 0)
	{
		//printf("\n**%d %d**\n", x, y);
		return -1;
	}
	
	answer[x][y] = -1;
	//printf("%d %d", x, y);
	printMatrix(answer, height, width);


	if (x > 0)
		result = play(arr, answer, height, width, x - 1, y, 1);
	if ((x + 1) < height)
	{
		n = play(arr, answer, height, width, x + 1, y, 1);
		if (n < result)
			result = n;
	}
	if ((y - 1) >= 0)
	{
		n = play(arr, answer, height, width, x, y - 1, 1);
		if (n < result)
			result = n;
	}
	if ((y + 1) < width)
	{
		n = play(arr, answer, height, width, x, y + 1, 1);
		if (n < result)
			result = n;
	}

	answer[x][y] = result;

	if (result == -1)
	{
		return -1;
	}
	else
	{
		answer[x][y] = result;
		return result + 1;
	}
}
int main(void)
{
	int width, height, i, j, result;
	int sIndexX, sIndexY;
	char **arr;
	int **answer;

	scanf("%d %d", &height, &width);

	arr = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		arr[i] = (char*)malloc(sizeof(char) * width);

	answer = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		answer[i] = (char*)malloc(sizeof(char) * width);

	for (i = 0; i < height; i++)
	{
		clear_stdin();

		for (j = 0; j < width; j++)
		{
			scanf("%c", &arr[i][j]);
			answer[i][j] = 0;

			if (arr[i][j] == 'S')
			{
				sIndexX = i;
				sIndexY = j;
			}
		}
	}

	result = play(arr, answer, height, width, sIndexX, sIndexY, 0);
	printMatrix(answer, height, width);

	printf("%d\n", result);

	for (i = 0; i < height; i++)
		free(arr[i]);
	free(arr);

	for (i = 0; i < height; i++)
		free(answer[i]);
	free(answer);
}