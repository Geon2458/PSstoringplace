#include <stdio.h>

int main(void)
{
	int h;
	scanf("%d", &h);
	int m;
	scanf("%d", &m);
	int t;
	scanf("%d", &t);
	
	if (24 > h && 60 > m + t)
	{
		printf("%d %d", h, m + t);
	}
	else if (24 > h && 60 <= m + t)
	{
		printf("%d %d", (h + (m + t)/60)%24, (m + t) % 60);
	}
	
	return 0;
}