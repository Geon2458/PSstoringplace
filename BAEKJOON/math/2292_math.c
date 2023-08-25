#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, a, b;                           // 입력할 수 n 과 범위를 위한 a와 b
	
	scanf("%d", &n);

	if (n == 1)                            // n 이 1일 때 1 출력
	{
		printf("1");
	}
	a = 2;                                 // for 문 시작전 a 를 2로 저장해 준 뒤 for 문 실행
	for (int j = 1; j < n; j++)            // a 부터 a+b까지 6의 배수로 범위가 넓어지기 때문 
	{
		b = 6*j;                           // b를 6의 배수로 저장
		for (int i = a; i < a+b; i++)      // a 부터 a+b 까지 범위로 지정하여 범위가 6의 배수 만큼 늘어남
		{
		   if (n == i)                     // 입력한 수 n과 i가 같을 때 출력
		   {
			   printf("%d", (b/6)+1);
			   exit(0);                    // for 문 반복을 막기 위해 break 이 아닌 exit 사용
		   }
		}
		a = a+b;                           // n 이 i 가 아닐 시 a = a+b 을 실행 하여 다음 범위로 실행
	}
	
	return 0;
}