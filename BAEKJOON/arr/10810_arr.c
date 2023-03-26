#include <stdio.h>

int main(void)
{
	int n, m, a, b, c;
	int arr[100] = {0};
	
	scanf("%d %d", &n, &m);            // n개의 바구니 m개의 공
	
	for (int i = 0; i < m; i++)        // m번 반복
	{
		scanf("%d %d %d", &a, &b, &c); // a부터 b까지 c번호를 가진 공
		for (int j = a; j <= b; j++)   // a부터 b까지
		{
			arr[j] = c;                // c번호를 가진 공을 arr에 저장
		}
	}
	
	for (int i = 1; i <= n; i++)       // n개의 바구니 속(arr[100])에 저장된 값
	{
		printf("%d ", arr[i]);         // 출력
	}
	
	return 0;
}