#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// �ΰ��� ���ڵ� ������ ǥ���� ���๮�ڿ��� ����ϰ� �� ���̸� ��ȯ�Ѵ�. 
int solution(char *s, int n)
{
	// �ڵ�
	char result[1001];
	int i, k, j = 0, count = 0, flag = 0;
	char d[100];

	for (i = 0; ; i += n)
	{
		for (k = i; k < i + n; k++)
		{
			if (s[k] == '\0')
			{
				if (count != 0)
					result[j++] = count + 1 + '0';

				for (; j < k; j++)
					result[j] = s[i + j];
				result[j] = '\0';

				printf("%s\n", result);
				return j;
			}
		}

		if (i == 0)
		{
			for (k = 0; k < n; k++)
			{
				d[k] = s[k];
				count = 0;
			}

			continue;
		}

		flag = 0;
		for (k = 0; k < n; k++)
		{
			if (d[k] != s[k + i])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			if (count != 0)
			{
				result[j++] = count + 1 + '0';
			}

			for (k = 0; k < n; k++, j++)
				result[j] = d[k];

			for (k = 0; k < n; k++)
			{
				d[k] = s[k];
				count = 0;
			}
		}
		else
			count++;
	}
}

int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("%d\n", solution(s, 2));
}