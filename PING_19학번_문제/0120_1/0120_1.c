#include <stdio.h>
#include <stdlib.h>

//���� ���� ('\n'/�ٹٲ� �� ���ڷ� �ν��� '\n'�� ���� ���� �ִ� ��찡 �ִ�. �̸� �����ϱ� ���� ���)
void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n' && ch != ' ') {};
}

//2���� �迭 ����ϴ� �Լ�
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

//'.'�� �ƴ� �ٸ� ������ ��� -1�� ��ȯ. (���� �ʾƵ� �����ƿ�!)
int other(char **arr, int x, int y)
{
	if (arr[x][y] == 'D' || arr[x][y] == '*' || arr[x][y] == 'X')
		return -1;
	else
		return 0;
}

//���� Ȯ���ϴ� �ڵ� ����
int water(char **arr, int height, int width)
{
	int i, j, result = 0;

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
				result = 1;
			}
		}
	}

	return result;
}

//�ð� ���ϴ� �ڵ� ���� (��� ���)
int solution(char ** arr, int height, int width)
{
	int result;

	result = water(arr, height, width);
	printMatrix(arr, height, width);

	if (result == 0)
		return result;
	else
		return 1 + solution(arr, height, width);
}
int main(void)
{
	int width, height, i, j, result;
	char **arr;

	scanf("%d %d", &height, &width);

	arr = (char **)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		arr[i] = (char*)malloc(sizeof(char) * width);
	/*
	malloc: �迭 �����Ҵ��� ���� ����ϴ� ��ɾ�
	�迭�� ũ�Ⱑ ��Ȯ�ϰ� �������� �ʾ��� ��� (ex> ����ڰ� �迭�� ũ�� ����) �ַ� ���
	����: https://dojang.io/mod/page/view.php?id=285
	*/

	for (i = 0; i < height; i++)
	{
		clear_stdin();

		for (j = 0; j < width; j++)
			scanf("%c", &arr[i][j]);
	}

	printf("%d\n", solution(arr, height, width));
	
	for (i = 0; i < height; i++)
		free(arr[i]);
	free(arr);
	/*
	free: �޸� �Ҵ� �����ϴ� ��ɾ�
	�޸� ���������� ���� ���� ���� ����Ѵ�.
	*/
}