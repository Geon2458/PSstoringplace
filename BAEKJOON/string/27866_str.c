#include <stdio.h>

int main(void)
{
	int a;
	char arr[1001] = {0};
	
	scanf("%s", arr);
	scanf("%d", &a);	
	
	printf("%c", arr[a - 1]);
	return 0;
}