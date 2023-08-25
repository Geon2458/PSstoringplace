#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[101] = {0};
	char str[101] = {0};
	
	scanf("%s", arr);
	
	for (int i = 0; i < strlen(arr); i++)
	{
		str[i] = arr[i];
	}
	
	for (int i = 0; i < strlen(arr) / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[(strlen(arr) -1) - i];
		arr[(strlen(arr) -1) - i] = temp;
	}

	int cnt = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == str[i])
		{
			cnt++;
		}
	}
	
	if (cnt == strlen(arr))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	
	return 0;
}