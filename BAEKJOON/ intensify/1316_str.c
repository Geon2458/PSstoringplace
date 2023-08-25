#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[101] = {0};
	char alph[26] = {0};
	int word, cnt = 0;
	
	scanf("%d", &word);
	
	for (int i = 0; i < word; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			alph[j] = 0;
		}
		
		scanf("%s", arr);
		
		for (int j = 0; j < strlen(arr); j++)
		{
			for (int k = 97; k <= 122; k++)
			{
				if (arr[j] == k && arr[j] != arr[j+1])
				{
					alph[k - 97] += 1;
				}
			}
		}
		
		int count = 0;
		for (int j = 0; j < 26; j++)
		{
			if (alph[j] < 2 && alph[j] > 0)
			{
				count++;
			}
			if (alph[j] > 1)
			{
				for (int k = 0; k < 26; k++)
				{
					alph[k] = 0;
					count = 0;
				}
			}
		}
		
		if (count > 0)
		{
			cnt++;
		}
	}

	printf("%d", cnt);
	
	return 0;
}