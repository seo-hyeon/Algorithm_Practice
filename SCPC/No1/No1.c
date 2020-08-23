#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b) {int t; t = a; a = b; b = t;}
void QuickSort(int *base, int n)

{

	int pivot = 0;
	int left = 0, right = n; 

	if (n <= 1)
	{
		return;
	}

	while (1)
	{
		for (left++; (left<n) && (base[0] >= base[left]); left++);
		for (right--; (right>0) && (base[0]<base[right]); right--);

		if (left<right)
		{
			SWAP(base[left], base[right]);
		}

		else
		{
			break;
		}
	}
	SWAP(base[0], base[right]);

	QuickSort(base, right);
	QuickSort(base + left, n - left);

}

void sort(int * arr, int n) 
{
	/*
	int i, j;

	for (i = 0; i < k; i++)
	{
		for (j = i; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				SWAP(arr[i], arr[j]);
			}
		}
	}*/
}
int main(void)
{
	setbuf(stdout, NULL);

	int t, n, k, i, j;
	int *a, *b;	
	int *ans;

	scanf("%d", &t);
	ans = (int *)malloc(sizeof(int) * t);

	for (i = 0; i < t; i++) 
	{
		scanf("%d %d", &n, &k);
		a = (int *)malloc(sizeof(int) * n);
		b = (int *)malloc(sizeof(int) * n);

		for (j = 0; j < n; j++) 
		{
			scanf("%d", &a[j]);
		}

		for (j = 0; j < n; j++)
		{
			scanf("%d", &b[j]);
		}
		
		QuickSort(a, n);
		QuickSort(b, n);
		//sort(a, n, k);
		//sort(b, n, k);
		
		ans[i] = -1;
		for (j = 0; j < k; j++)
		{
			if (ans[i] < a[j] + b[k - j - 1])
				ans[i] = a[j] + b[k - j - 1];
		}

		free(a);
		free(b);
	}

	for (i = 0; i < t; i++)
	{
		printf("Case #%d\n", i + 1);
		printf("%d\n", ans[i]);
	}
	free(ans);
	return 0;
}