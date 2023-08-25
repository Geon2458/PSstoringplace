#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char num1[101] = {0};
	char num2[101] = {0};
	
	scanf("%s %s", num1, num2);

	int temp = num1[0];
	num1[0] = num1[2];
	num1[2] = temp;
	
	int swap = num2[0];
	num2[0] = num2[2];
	num2[2] = swap;
	
	int a = atoi(num1);
	int b = atoi(num2);
	
	if (a > b)
	{
		printf("%d", a);
	}
	
	if (a < b)
	{
		printf("%d", b);
	}
	
	return 0;
}