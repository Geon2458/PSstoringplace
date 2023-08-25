#include <stdio.h>

int main(void)
{
	int N, arr[1000000];
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int MIN = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (MIN > arr[i])
		{
			MIN = arr[i];
		}
	}
	int MAX = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (MAX < arr[i])
		{
			MAX = arr[i];
		}
	}
	printf("%d %d", MIN, MAX);
	
	return 0;
}