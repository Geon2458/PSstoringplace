#include <stdio.h>

int main(void)
{
	int h;
	scanf("%d", &h);
	int m;
	scanf("%d", &m);
	
	// 45 > m
	if (0 < h && 45 > m)
	{
		printf("%d %d", h - 1, (60 + m) - 45);
	}
	//  0 = h
	else if (0 == h && 45 > m)
	{
		printf("%d %d", 24 - 1, (60 + m) - 45);
	}
	// 45 < m
	else
	{
		printf("%d %d", h , m - 45);
	}
	
	return 0;
}