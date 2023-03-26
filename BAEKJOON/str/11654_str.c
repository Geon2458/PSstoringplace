#include <stdio.h>

int main(void)
{
	char arr[1] = {0};
	
	scanf("%s", arr);
	
	for (int i = 0; i < sizeof(arr); i++)
	{
		printf("%d", arr[i]);
	}
	
	return 0;
}