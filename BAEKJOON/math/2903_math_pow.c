#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, a, b;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int res = pow (2 ,i);
		a = (1+res);
		b = a+res;
	}

	printf("%d", b*b);
	
	return 0;
}