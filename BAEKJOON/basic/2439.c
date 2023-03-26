#include <stdio.h>

int main(void)
{
	int star;
	scanf("%d", &star);
	
	for (int i = 1; i <= star; i++)
	{
		for (int j = i; j < star; j++)
		{
			printf(" ");
		}
		for (int k = 1; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}