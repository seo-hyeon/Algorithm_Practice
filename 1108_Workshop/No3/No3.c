#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// �ΰ��� ���ڵ� ������ ǥ���� ���๮�ڿ��� ����ϰ� �� ���̸� ��ȯ�Ѵ�. 
int solution(char *s)
{
	// �ڵ�
	char result[1001];
	int i, j = 0, count = 0;
	char d[2];

	for (i = 0; s[i] != '\0' && s[i + 1] != '\0'; i += 2)
	{
		if (s[i + 1] == '\0' && i == 0)
		{
			printf("%c\n", s[0]);
			return 1;
		}
		else if (i == 0)
		{
			d[0] = s[i];
			d[1] = s[i + 1];
			count = 0;
		}
		else if (d[0] != s[i] || d[1] != s[i + 1])
		{
			if (count != 0)
				result[j++] = count + 1 + '0';

			result[j++] = d[0];
			result[j++] = d[1];

			d[0] = s[i];
			d[1] = s[i + 1];
			count = 0;
			result[j] = d;
		}
		else
			count++;
	}

	if (count != 0)
		result[j++] = count + 1 + '0';

	result[j++] = d[0];
	result[j++] = d[1];

	if (s[i] != '\0')
		result[j++] = s[i];

	result[j] = '\0';

	printf("%s\n", result);

	return j;
}

int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("%d\n", solution(s));
}