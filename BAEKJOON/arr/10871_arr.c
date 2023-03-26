#include <stdio.h>

int main(void)
{
	int N, X, arr[10000];
	
	scanf("%d", &N);
	scanf("%d", &X);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int j = 0; j < N; j++)
	{
		if (arr[j] < X)
		{
			printf("%d ", arr[j]);
		}
	}
	
	return 0;
}