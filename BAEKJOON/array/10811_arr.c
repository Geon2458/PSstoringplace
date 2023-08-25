#include <stdio.h>

void swap(int * a, int * b);

int main(void)
{
	int n, m, a, b;
	int arr[101];
	
	scanf("%d %d", &n, &m); // 바구니의 갯수와 역순으로 할 바구니의 순서
	
	for (int i = 1; i <= n; i++) // 1부터 순서대로
	{
		arr[i] = i;
	}
	
	for (int i = 0; i < m; i++) // 역순으로 할 바구니 횟수
	{
		scanf("%d %d", &a, &b);
		for (int k = 0; k < (b - a + 1)/2; k++)
		{
			swap(&arr[a + k], &arr[b - k]);
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}