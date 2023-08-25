#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, b;
	
	scanf("%d", &a);
	
	for (int i = 0; i < a; i++)
	{
		char arr[101] = {0};
		scanf("%d", &b);
		scanf("%s", arr);
		for (int j = 0; j < strlen(arr); j++)
		{
			for (int k = 0; k < b; k++)
			{
				printf("%c", arr[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}