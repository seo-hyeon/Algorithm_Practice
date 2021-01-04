#include <stdio.h>

int main(void)
{
	int hour, minute;

	scanf("%d %d", &hour, &minute);

	if (minute < 45)
	{
		if (hour < 1)
		{
			hour = 23;
		}
		else
		{
			hour -= 1;
		}
		minute += 60;
	}

	minute -= 45;

	printf("%d %d", hour, minute);
}