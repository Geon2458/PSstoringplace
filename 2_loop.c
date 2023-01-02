#include <stdio.h>

int main(void)
{
	// Project 별짓기
	// 왼족 별 오른쪽 별 거꾸로 별 피라미드 별
	
	// 왼쪽 별
	/*
	int flo;
	scanf("%d", &flo);
	for (int i = 1; i <= flo; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/
	
	// 오른쪽 별
	/*
	int flo;
	scanf("%d", &flo);
	for(int i = 1; i <= flo; i++)
	{
		for(int j = i; j <= flo - 1; j++)
		{
			printf(" ");
		}	
		for(int k = 1; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/
	
	// 거꾸로 별
	/*
	int flo;
	scanf("%d", &flo);
	for(int i = 1; i <= flo; i++)
	{
		for(int j = i; j <= flo; j++)
		{
			printf("*");
		}	
		for(int k = 1; k <= i; k++)
		{
			printf(" ");
		}
		printf("\n");
	}
	*/
	
	// 피라미드 별
	int flo;
	scanf("%d", &flo);
	for(int i = 1; i <= flo; i++)
	{
		for(int j = i; j <= flo - 1; j++)
		{
			printf(" ");
		}	
		for(int k = 1; k <= i*2 - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}