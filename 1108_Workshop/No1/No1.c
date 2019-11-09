#include <stdio.h>
void solution(char* s)
{
	char result[1000];
	int i, j = 0, count = 0;
	char d;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0)
		{
			d = s[i];
			count = 0;
		}
		else if (s[i] != s[i - 1])
		{
			if (count != 0)
				result[j++] = count+ 1 + '0';
			
			result[j++] = d;

			d = s[i];
			count = 0;
			result[j] = d;
		}
		else
			count++;
	}

	if (count != 0)
		result[j++] = count + 1 + '0';

	result[j++] = d;
	result[j] = '\0';

	printf("%s", result);
}
int main(void)
{
	char sentence[1000];

	scanf("%s", sentence);

	solution(sentence);
}