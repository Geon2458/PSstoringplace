#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000001] = {0};
	int cnt = 0;
	
	scanf("%[^\n]", str);
	
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0')
		{
			cnt ++;
		}
	}
	
	if (str[0] == ' ')
	{
		printf("%d", cnt);
	}
	else
	{
		printf("%d", cnt + 1);
	}
	
	return 0;
}