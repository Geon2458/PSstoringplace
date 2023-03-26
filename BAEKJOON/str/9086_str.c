#include <stdio.h>
#include <string.h>

int main(void)
{
	int a; 
	char arr[1001] = {0};
	
	scanf("%d", &a);
	
	for (int i = 0; i < a; i++)
	{
		int b;
		scanf("%s", arr);
		b = strlen(arr);
		printf("%c%c\n", arr[0], arr[b - 1]);
	}
	
	
	return 0;
}