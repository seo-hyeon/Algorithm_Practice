//น้มุ 14505น๘ https://www.acmicpc.net/problem/14505
#include <stdio.h>
int palindrome(char string[])
{
	int i, size;

	for (size = 0; string[size] != '\0'; size++);

	for (i = 0; size - i - 1 > i; i++)
		if (string[i] != string[size - i - 1])
			return 0;

	return 1;
}
int solution(char string[])
{
	int size, result;

	for (size = 0; string[size] != '\0'; size++);

	result = size;


}
int main(void)
{
	char string[30];
	int flag;

	scanf("%s", string);

	printf("%d", solution(string));
}