#include <stdio.h>

int main(void)
{
	int num1, a, b, cnt, num2;
	int square[101][101] = {0,};
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			square[i][j] = num1+=1;
		}
	}
	
	scanf("%d", &cnt);
	int count2 = 0;
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d %d", &a, &b);
		int count1 = 0;
		for (int j = a; j < a+10; j++)
		{
			for (int k = b; k < b+10; k++)
			{
				if (square[j][k] == -1)
				{
					square[j][k] = -2;
				}
				else 
				{
					square[j][k] = -1;
				}
				if (square[j][k] == -2)
				{
					count1++;
					square[j][k] = -1;  	// 풀리지 않았던 문제의 부분 count1 을 실행한 후 다시 -2인 square[j][k]를 -1로 변환
				}
			}
		}
		if (count1 > 0)
		{
			count2 += count1;
		}
	}

	printf("%d", cnt*100 - count2);
	
	return 0;
}