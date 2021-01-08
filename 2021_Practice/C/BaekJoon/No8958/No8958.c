#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, i, j, result, k;
	char input[81];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		result = 0;
		k = 1;

		for (j = 0; input[j] != '\0'; j++)
		{
			if (input[j] == 'O')
			{
				result += k;
				k += 1;
			}
			else
			{
				k = 1;
			}
		}

		printf("%d\n", result);
	}
}