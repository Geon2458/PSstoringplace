#include <stdio.h>

int main(void)
{
	int num, arr[100], v, count = 0;
	
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	scanf("%d", &v);
	
	for (int j = 0; j < num; j++)
	{
		if (arr[j] == v)
		{
			count++;
		}
	}
	printf("%d", count);
	
	return 0;
}