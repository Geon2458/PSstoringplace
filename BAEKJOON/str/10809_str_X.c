#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101] = {0};
	char arr[26];
	
	scanf("%s", str);
	// a 97 ~ z 122

	for (int i = 0; i < 26; i++)
	{
		arr[i] = -1;
	}
	
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 97; j <= 122; j++)
		{
			if (str[i] == j && arr[j - 97] == -1 )
			{
				arr[j - 97] = i;
				break;
			}
		}
	}
	
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}


/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101] = {0};
	char arr[26];
	
	scanf("%s", str);
	// a 97 ~ z 122

	for (int i = 0; i < 26; i++)
	{
		arr[i] = -1;
	}
	
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 97; j <= 122; j++)
		{
			if (str[i] == j)
			{
				arr[j - 97] = j - 97;
				break;
			}
		}
	}
	
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
*/