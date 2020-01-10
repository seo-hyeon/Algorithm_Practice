//น้มุ 1085น๘  https://www.acmicpc.net/problem/1085
#include <stdio.h>
int main(void)
{
	int x, y, w, h;
	int result;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (x > y)
		result = y;
	else
		result = x;

	if (result > w - x)
		result = w - x;
	if (result > h - y)
		result = h - y;

	printf("%d", result);
}