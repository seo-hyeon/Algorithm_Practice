#include <stdio.h>
typedef struct {
	int m;
	int n;
	int x;
	int y;
} element;

//최대공약수 구하는 함수
int gcd(int n, int m)
{
	int i;

	for (i = 2; i <= n && i <= m; i++)
		if (n % i == 0 && m % i == 0)
			return i * gcd(n / i, m / i);

	return n * m;
}
/*
int cal(element num)
{
	int g = gcd(num.m, num.n);
	int total = 0;
	
	while (num.x < g && num.y < g)
	{
		if ((num.x %  == num.m)
		{
			num.y =(num.y + total) % num.n;

			if (num.y == num.n)
				return num.x;

			total = 0;
		}

		num.x += num.m;
		total += num.m;
	}
	return -1;
}*/
//런타임에러
int cal(element num)
{
	int g = gcd(num.m, num.n);
	while (num.x != num.y && num.x < g && num.y < g)
	{
		if (num.x > num.y)
			num.y += num.n;
		else
			num.x += num.m;
	}

	if (num.x > g || num.y > g)
		return -1;
	else
		return num.x;
}
int main(void)
{
	element num;
	int count, i;
	int result[100];

	scanf("%d", &count);

	for (i = 0; i < count; i++)
	{
		scanf("%d %d %d %d", &num.m, &num.n, &num.x, &num.y);
		result[i] = cal(num);
	}

	for (i = 0; i < count; i++)
		printf("%d\n", result[i]);
}