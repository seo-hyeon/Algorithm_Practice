//น้มุ 1157น๘ https://www.acmicpc.net/problem/1157
#include <stdio.h>
int main(void)
{
	char word[1000001];
	int alpabet[26] = { 0 };
	int i, max, index;

	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
			alpabet[word[i] - 'a']++;
		else if (word[i] >= 'A' && word[i] <= 'Z')
			alpabet[word[i] - 'A']++;
	}

	max = -1;

	for (i = 0; i < 26; i++)
	{
		if (max < alpabet[i])
		{
			max = alpabet[i];
			index = i;
		}
		else if (max == alpabet[i])
			index = -1;
	}

	if (index == -1)
		printf("?");
	else
		printf("%c", 'A' + index);
}