#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
long long int cal(long long int a, long long int b, int op)
{
	switch (op)
	{
		case 0:
			return a + b;
		case 1:
			return a - b;
		case 2:
			return a * b;
	}

	return 0;
}

long long int b_tracking(int index, long long int s[], int length)
{
	int i = 0;
	long long int result = 0, result2 = 0;
	int j = 0;
	long long int *ss;

	if (index >= length-1)
	{
		result = cal(result, s[0], 0);
		for (i = 2; i < length; i += 2)
		{
			result = cal(result, s[i], s[i - 1]);
		}

		return result;
	}

	for (i = index; i < length; i += 2)
	{
		result = b_tracking(index + 2, s, length);


		ss = (long long int*)malloc(sizeof(long long int) * length);

		for (j = 0; j < index; j++)
			ss[j] = s[j];
		
		ss[index] = cal(s[index], s[index + 2], s[index + 1]);

		for (j = index + 3; j < length; j++)
			ss[j - 2] = s[j];

		result2 = b_tracking(index + 2, ss, length - 2);

		for (j = 0; j < length; j++)
		{
			if (j % 2 == 0)
				printf("%d", s[j]);
			else
				switch (s[j])
				{
				case 0:
					printf("+");
					break;
				case 1:
					printf("-");
					break;
				case 2:
					printf("*");
					break;
				}
		}
		printf("\n");
		for (j = 0; j < length - 2; j++)
		{
			if (j % 2 == 0)
				printf("%d", ss[j]);
			else
				switch (ss[j])
				{
				case 0:
					printf("+");
					break;
				case 1:
					printf("-");
					break;
				case 2:
					printf("*");
					break;
				}
		}
		printf("\n");

		printf("%d %d %d %d\n\n", index, length, result, result2);

		if (result > result2)
			return result;
		else
			return result2;
	}
}

int main(void)
{
	int length, i;
	long long int result = 0;
	long long int* calList;
	char j;

	scanf("%d", &length);
	getchar();

	calList = (long long int*)malloc(sizeof(long long int) * length);

	for (int i = 0; i < length; )
	{
		j = getchar();
		
		if ((j >= '0' && j <= '9'))
		{
			calList[i] = j - '0';
			i++;
		}
		else if (j == '+' || j == '-' || j == '*')
		{
			switch (j) 
			{
				case '+': 
					calList[i] = 0;
					break;
				case '-':
					calList[i] = 1;
					break;
				case '*':
					calList[i] = 2;
					break;
			}
			i++;
		}
	}

	//printf("============================================\n");
	result = b_tracking(0, calList, length);
	//printf("============================================\n");
	printf("%d", result);

	free(calList);
}