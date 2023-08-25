#include <stdio.h>

int main(void)
{
	int QDNP[4] = {25, 10, 5, 1};
	int c;                         // 입력 받을 거스름돈
	int arr[101] = {0};
	int t;                                  // test case
	
	scanf("%d", &t);                        // test case 개수 입력
	
	for (int i = 0; i < t; i++)             // t번 거스름돈 입력
	{
		scanf("%d", &c);
		for (int j = 0; j < 4; j++)
		{
			arr[j] = c/QDNP[j];
			c = c%QDNP[j];
			printf("%d ", arr[j]);
		}
	}
	return 0;
}