#include <stdio.h>

int main(void)
{
	char str[101];
	
	while ((str[101] = getchar()) != EOF)
	{
		putchar(str[101]);
	}
	
	return 0;
}