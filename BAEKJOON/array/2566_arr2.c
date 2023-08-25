#include <stdio.h>

int main(void)
{
	int arr[101][101];
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d ", &arr[i][j]);
		}
	}
	
	int max = 0;
	int cnt = 0, count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				count = i;
				cnt = j;
			}
		}
	}
	
	printf("%d\n%d %d", max, count+1, cnt+1);
	
	return 0;
}