#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[6][16] = {0,};
	int s;
	
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", str[i]);
	}
	for (int k = 0; k < 16; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (str[i][k] == '\0')
			{
				continue;
			}
			printf("%c", str[i][k]);
		}
	}
	
	return 0;
}