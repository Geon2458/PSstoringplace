#include <stdio.h>

int main(void)
{
	char arr[26] = {0};
	
	scanf("%s", arr);
	int cnt =0;
	for (int i = 1; i < 72; i++)
	{
		cnt = i;
		printf("%d ", i);
	}
	printf("\n%d", cnt+1);
	return 0;
}