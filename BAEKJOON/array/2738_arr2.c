#include <stdio.h>

int main(void)
{
	int n, m;
	int arr[101][101], arr2[101][101];
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		for (int l = 0; l < m; l++)
		{
			scanf("%d", &arr2[k][l]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j] + arr2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}