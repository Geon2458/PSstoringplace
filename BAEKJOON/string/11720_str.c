#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int sum = 0;
	
	scanf("%d", &a);
	
	for (int i = 0; i < a; i++)
	{
		scanf("%1d", &b);        // 1d = 한 글자, 2d = 두 글자, 3d = 세 글자
		sum += b;
	}
	
	printf("%d", sum);
	
	return 0;
}