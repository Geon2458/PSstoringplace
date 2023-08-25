#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	카드 수 n장 숫자 m
	
	n장 중 m을 넘지 않으면서 m에 가까운 3장의 숫자의 합
	
	3장 선정 어떻게? ... 3중 for문?
	
	모든 경우의 수? □□□ 100 99 98
	
	m >= sum
	*/
	
	int n, m;
	int card[101], sum[970201];
	
	scanf("%d %d", &n, &m);                          // n장의 카드 제한 숫자m
	
	for (int i = 0; i < n; i++){                     // n장의 카드에 적을 숫자
		scanf("%d", &card[i]);
	}
	
	int max = sum[0];                                // n장의 카드중 3장의 카드를 더한 값 중 최댓값
	for (int i = 0; i < n; i++){                     // 첫 번째 카드의 경우의 수 n 가지
		for (int j = i+1; j < n; j++){               // 두 번째 카드의 경우의 수 n-1 가지
			for (int k = j+1; k < n; k++){           // 세 번째 카드의 경우의 수 n-2 가지
				sum[i] = card[i]+card[j]+card[k];    // 세 장의 카드를 더한 값을 배열 sum에 저장
				if (sum[i] <= m){                    // 배열 sum의 값이 m보다 작거나 같으면 if문 실행
					if (max < sum[i])                // max의 값이 배열 sum[i] 보다 작다면
					{
						max = sum[i];                // max에 sum의 값 저장
					}
				}
			}
		}
	}
	
	printf("%d\n", max);                              // 숫자 m보다 작거나 같은 수 중 가장 큰 수 출력
	
	return 0;
}