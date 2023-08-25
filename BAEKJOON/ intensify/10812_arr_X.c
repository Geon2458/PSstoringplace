#include <stdio.h>

int main(void)
{
	int n, m, begin, mid, end;
	int arr[101];
	
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) // 1 부터 n까지 오름차순
	{
		arr[i] = i;
	}
	
	for (int j = 0; j < m; j++)  // 바구니를 m번 바꿈
	{
		scanf("%d %d %d", &begin, &end, &mid);
		for (int k = begin; k < mid; k++)
		{
			for (int l = end; l >= mid; l--)
			{
				int temp = arr[k];
				arr[k] = arr[l];
				arr[l] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}