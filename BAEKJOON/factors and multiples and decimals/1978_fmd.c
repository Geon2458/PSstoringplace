#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	입력한 수의 약수가 1을 제외한 자기자신 뿐인가?
	
	cnt를 이용하여 cnt < 3 -> count
	*/
	
	int n, count = 0;
	int num[101];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){                // 배열 num에 n개의 숫자를 입력하여 저장
		scanf("%d", &num[i]);
		int cnt = 0;                            // 반복문을 돌때마다 0으로 초기화
		for (int j = 1; j < 1001; j++){         // 1000이하의 자연수 이므로
			if (num[i]%j == 0 && num[i] >= j){  // 쓸데없는 나누기를 막기 위해 num[k] 보다 같거나 작은 수 까지만 계산
				cnt += 1;
			}
		}
		if (cnt == 2){                          // 소수는 약수가 항상 2개 이므로
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}