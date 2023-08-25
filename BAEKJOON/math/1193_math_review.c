#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int n, a, b, c, d, e, sum, cnt = 0;             // 입력할 수 n 분자 a 분모 b

	scanf("%d", &n);
	
	/*
	n = 1                   -> sum = 2
	n = 2, 3                -> sum = 3
	n = 4, 5, 6             -> sum = 4
	n = 7, 8, 9, 10         -> sum = 5
	n = 11, 12, 13, 14, 15  -> sum = 6
	1
	2 ~ 3
	4 ~ 6
	*/
	
	c = 1;
	for (int i = 1; i <= 4472; i++)
	{
		d = c+i;                                    // d ... 2, 4, 7, 11, 16 ... 
		for (int j = c; j < d; j++)
		{
			if (j == n)
			{
				sum = (d-c)+1;
				e = c;                               // 시작 숫자를 e에 저장
				break;
			}
		}
		c = d;                                      // c ... 1, 2, 4, 7, 11, 16 ...
	}
	for (int i = 1; i <= 4472; i++){
		a = i;
		for (int j = 1; j <= 4472; j++){
			b = j;
			if (a+b == sum && sum%2 == 0){
				cnt += 1;                            // 몇번째 숫자인지 출력
				if ((n-e)+1 == cnt){                 // n-e를 통해 마지막 숫자 - 처음 숫자 +1
					printf("%d/%d", b, a);           // sum이 짝 수 일 때 분모 b 분자 a
				}
			}
			else if (a+b == sum){
				cnt += 1;
				if ((n-e)+1 == cnt){
					printf("%d/%d", a, b);           // sum이 홀 수 일 때 분모 a 분자 b
				}
			}
		}
	}
	
	return 0;
}

// https://www.acmicpc.net/board/view/98750 참고