//น้มุ 1075น๘ https://www.acmicpc.net/problem/1075
#include <stdio.h>
int main(void)
{
	int num, small;
	int n, result;

	scanf("%d", &num);
	scanf("%d", &small);

	n = num % small;
	result = num % 100 - n;

	while (result >= 0)
	{
		result -= small;
	}
	result += small;

	if (result < 10)
		printf("%d%d", 0, result);
	else
		printf("%d", result);
}