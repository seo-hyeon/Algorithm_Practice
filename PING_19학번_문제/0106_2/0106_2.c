//น้มุ 1547น๘ https://www.acmicpc.net/problem/1547
#include <stdio.h>
int main(void)
{
	int num, i, n1, n2;
	int result = 1;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &n1, &n2);

		if (n1 == result)
			result = n2;
		else if (n2 == result)
			result = n1;
	}

	printf("%d", result);
}