#include <stdio.h>
#include <stdlib.h>

//버퍼 비우기 ('\n'/줄바꿈 을 문자로 인식해 '\n'을 변수 값에 넣는 경우가 있다. 이를 방지하기 위해 사용)
void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n' && ch != ' ') {};
}

//2차원 배열 출력하는 함수
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

//'.'이 아닌 다른 문자일 경우 -1을 반환. (쓰지 않아도 괜찮아요!)
int other(char **arr, int x, int y)
{
	if (arr[x][y] == 'D' || arr[x][y] == '*' || arr[x][y] == 'X')
		return -1;
	else
		return 0;
}

//물이 확장하는 코드 구현
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

//시간 구하는 코드 구현 (재귀 사용)
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
	malloc: 배열 동적할당을 위해 사용하는 명령어
	배열의 크기가 정확하게 정해지지 않았을 경우 (ex> 사용자가 배열의 크기 지정) 주로 사용
	참고: https://dojang.io/mod/page/view.php?id=285
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
	free: 메모리 할당 해제하는 명령어
	메모리 부족해지는 것을 막기 위해 사용한다.
	*/
}