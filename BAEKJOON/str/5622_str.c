#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[16] = {0}; 
	
	//A ~ Z = 65 ~ 90
	
	scanf("%s", str);
	
	for (int j = 0; j < 15; j++)
	{
		if (str[j] >= 'A' && str[j] <= 'C')
		{
			str[j] = '2';
		}
		else if (str[j] >= 'D' && str[j] <= 'F')
		{
			str[j] = '3';
		}
		else if (str[j] >= 'G' && str[j] <= 'I')
		{
			str[j] = '4';
		}
		else if (str[j] >= 'J' && str[j] <= 'L')
		{
			str[j] = '5';
		}
		else if (str[j] >= 'M' && str[j] <= 'O')
		{
			str[j] = '6';
		}
		else if (str[j] >= 'P' && str[j] <= 'S')
		{
			str[j] = '7';
		}
		else if (str[j] >= 'T' && str[j] <= 'V')
		{
			str[j] = '8';
		}
		else if (str[j] >= 'W' && str[j] <= 'Z')
		{
			str[j] = '9';
		}
	}
	
	int sum = 0;
	
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 50; j <= 57; j++)
		{
			if (str[i] == j)
			{
				str[i] = j - 47;
			}
		}
		sum += str[i];
	}
	
	printf("%d", sum);
	
	return 0;
}