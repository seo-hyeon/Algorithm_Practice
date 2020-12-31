#include <stdio.h>

int ten(int size)
{
	int i, result = 1;

	for (i = 0; i < size; i++)
	{
		result *= 10;
	}

	return result;
}

int main(void)
{
	int num1, num2, i, size;

	scanf("%d", &num1);
	scanf("%d", &num2);

	for (i = num2, size = 0; i != 0; i /= 10, size++);
	
	for (i = 0; i < size; i++) 
	{
		printf("%d\n", num1 * (num2 % ten(i + 1) / ten(i)));
	}

	printf("%d\n", num1 * num2);
	
	/*
	printf("%d\n", num1 * (num2 % 10));
	printf("%d\n", num1 * (num2 % 100 / 10));
	printf("%d\n", num1 * (num2 / 100));
	printf("%d\n", num1 * num2);
	*/
	
}