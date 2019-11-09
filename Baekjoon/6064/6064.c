#include <stdio.h>
typedef struct {
	int m;
	int n;
	int x;
	int y;
} element;

//최대공약수 구하는 함수
int gcd(int a, int b)
{
	int r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

/*int gcd(int a, int b)
{
	int i;

	for (i = 2; i <= n && i <= m; i++)
	if (n % i == 0 && m % i == 0)
	return i * gcd(n / i, m / i);

	return n * m;
}*/

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

//런타임에러
/*
int cal(element num)
{
	int g = lcm(num.m, num.n);
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
}*/

int cal(element num)
{
	int g = lcm(num.m, num.n);
	int a = gcd(num.m, num.n);
	int n = 0, total = 0;

	do
	{
		do
		{
			n = (n + a) % num.m;
			total += a;
		} while (n != num.x);
	} while (total % num.n != num.y && total <= g);

	if (total > g)
		return -1;
	else
		return total;
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