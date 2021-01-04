#include <stdio.h>

int main(void)
{
	int x, y;

	scanf("%d", &x);
	scanf("%d", &y);

	if (y > 0)
	{
		if (x > 0)
		{
			printf("1");
		}
		else
		{
			printf("2");
		}
	}
	else
	{
		if (x > 0)
		{
			printf("4");
		}
		else
		{
			printf("3");
		}
	}
}