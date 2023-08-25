#include <stdio.h>

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < 2*i + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for (int l = 0; l < n - 1; l++)
	{
		for (int m = 0; m < l + 1; m++)
		{
			printf(" ");
		}
		for (int v = l; v < 2*n - (l + 3); v++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}