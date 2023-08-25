#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101];
	int count = 0;
	
	scanf("%s", str);
	
	int slen = strlen(str);
	
	for (int i = 0; i < slen; i++)
	{
		count ++;
		if (str[i] == 'c' && str[i + 1] == '='
		   || str[i] == 'c' && str[i + 1] == '-'
		   || str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=' 
		   || str[i] == 'd' && str[i + 1] == '-'
		   || str[i] == 'l' && str[i + 1] == 'j' 
		   || str[i] == 'n' && str[i + 1] == 'j'
		   || str[i] == 's' && str[i + 1] == '=' 
		   || str[i] == 'z' && str[i + 1] == '=')
		{
			count --;
		}
	}
	
	printf("%d", count);
	
	return 0;
}

// 다른 방법은?