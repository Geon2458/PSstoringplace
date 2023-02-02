#include <stdio.h>

int main(void)
{
	int arr[6];
	int arry[6] = {1, 1, 2, 2, 2, 8};
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int j = 0; j < 6; j++)
	{
		printf("%d ", arry[j] - arr[j]);
	}
	
	return 0;
	
	int temp;
	for(int i = 0 ; i < 6 ; i ++){
		scanf("%d",&temp);
		printf("%d ",arry[i] - temp);
	}
}