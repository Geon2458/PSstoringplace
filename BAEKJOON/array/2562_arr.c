#include <stdio.h>

int main(void)
{
	int arr[9], cnt, Max = 0;
	
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		if (Max < arr[i])
		{
			Max = arr[i];
			printf("%d %d\n", Max, arr[i]);
			cnt = i; // 몇 번째 i?
		}
	}
	printf("%d\n%d", Max, cnt+1);
	
	return 0;
}


/*
#include <stdio.h>

int main(void)
{
	int arr[100], cnt = 0; // 처음 초기화 값인 cnt를 0으로 선정하지 않았기 때문에 값이 무작위로 나온다 그러므로 0을 넣어줘야 한다. 
	
	
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int Max = arr[0];
	for (int j = 1; j < 9; j++)
	{
		if (Max < arr[j])
		{
			Max = arr[j];
			cnt = j; // 몇 번째 j?
		}
	}
	
	printf("%d\n%d", Max, cnt+1);
	
	return 0;
}
*/