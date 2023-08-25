#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000001];
	int count, cnt, arr[26] = {0};
	
	scanf("%s", str);
	
	int slen = strlen(str); 
	
	/* 
	   for 문에 strlen을 사용하면
	   매번 loop할 때 마다 문자열의 길이를 다시 계산하므로 
	   성능에 악영향을 끼칠 수 있기 때문에 따로 저장해 두어야함. 
	*/
	
	for (int i = 0; i < slen; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			if (str[i]%32 == j)
			{
				arr[j] += 1;
				break;
			}
		}
	}
	
	int max = 0;
	int Max = 0;
	for (int i = 26; i >= 1; i--)
	{
		if(max < arr[i])
		{
			max = arr[i];
			count = i;
		}
		for (int j = 1; j <= 26; j++)
		{
			if(Max < arr[j])
			{
				Max = arr[j];
				cnt = j;
			}
		}
	}
	
	if (Max == max && cnt == count)
	{
		printf("%c", cnt+64);
	}
	else if (Max == max && cnt != count)
	{
		printf("?");
	}
	
	return 0;
}