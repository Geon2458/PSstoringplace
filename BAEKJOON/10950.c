#include <stdio.h>

int main(void)
{
	int j;
	scanf("%d", &j);
	
	for (int i = 0; i < j; i++)
	{
		int A;
		scanf("%d", &A);
		int B;
		scanf("%d", &B);
		printf("%d\n", A + B);
	}
	
	return 0;
}