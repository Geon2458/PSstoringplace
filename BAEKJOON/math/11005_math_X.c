#include <stdio.h>

int main(void)
{
	char n[30] = {0};
	long long a, b, x, count = 0;
	
	scanf("%lld %lld", &a, &b);
	
	if (b >= 10)
	{
		if (a == 0)                        // a이가 0일시 0 출력 
		{
			printf("0");
		}
		for (int i = 0; a != 0; i++)       // i번 만큼 count
		{
			if (a/b >= 0)
			{
				n[i] = a%b;
				a = a/b;
				count+=1;
			}
		}
		for (int j = 0; j < count/2; j++)  // 배열을 순서대로 정렬
		{
			int temp = n[j];
			n[j] = n[(count-1)-j];
			n[(count-1)-j] = temp;
		}
		
		for (int k = 0; k < count; k++)
		{
			for(int i = 10; i < b; i++)     // n[k]에 저장된 숫자를 아스키코드로 변환  10 ~ b진수
			{
				if (n[k] == i)
				{
					n[k] = i+'A'-10;
				}
			}
			for (int j = 0; j < 10; j++)    // n[k]에 저장된 숫자를 아스키코드로 변환  0 ~ 9
			{
				if (n[k] == j)
				{
					n[k] = j+'0';
				}
			}
		}
	}
	else if (b <= 9)
	{
		if (a == 0)                        // a이가 0일시 0 출력 
		{
			printf("0");
		}
		for (int i = 0; a != 0; i++)
		{
			if (a/b >= 0)                  // 실행된 i번 만큼 count +1
			{
				n[i] = a%b;
				a = a/b;
				count+=1;
			}
		}
		for (int j = 0; j < count/2; j++)  // 배열을 순서대로 정렬
		{
			int temp = n[j];
			n[j] = n[(count-1)-j];
			n[(count-1)-j] = temp;
		}
		
		for (int k = 0; k < count; k++)     // 9진수 이하 출력
		{
			n[k] = n[k] + '0';
		}
	}
	
    printf("%s", n);                        // 10진수 이상 출력  
	
    return 0;
}