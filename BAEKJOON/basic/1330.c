#include <stdio.h>

int main(void)
{
	int A;
	scanf("%d", &A);
	int B;
	scanf("%d", &B);
	
	if (A > B)
	{
		printf(">");
	}
	else if (A < B)
	{
		printf("<");
	}
	else if (A == B)
	{
		printf("==");
	}
	
	return 0;
}