#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	while (1)
	{
		int A;
		scanf("%d", &A);
		int B;
		scanf("%d", &B);
		if (A > 0 && B < 10)
		{
		printf("%d\n", A + B);	
		}
		else if(A == 0 && B == 0)
		{
			exit(0);
		}
	}
	
	return 0;
}