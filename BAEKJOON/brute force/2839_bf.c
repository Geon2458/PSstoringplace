#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	N%5 or N%3 == 0
	
	최소 몇 봉지?
	cnt++ count++
	
	만들 수 없다면 '-1' 출력
	*/
	int n, cnt = 0, count = 0;
	
	scanf("%d", &n);
	
	int k = n;                              // n의 값을 사용하기 위해 k에 따로 저장
	
	for (int i = 1; i <= k; i++){           
		for (int j = 1; j <= k; j++){
			if (k%5 == 0){                  // 큰 수인 5부터 나누면서 실행
				cnt = k/5;                  // cnt = k/5;
			}
			else if (k-3 != 5*j){           // 5의 배수가 아닐시 k-3을 계속 반복
				k = k-3;
				count++;                    // 몇 번 반복을 하였는지 count
			}
		}
	}
	if (count*3+cnt*5 != n){                // count*3+cnt*5가 n이 아니라면 n킬로그램을 만들 수 없다는 뜻이므로
		printf("-1\n");
	}
	else{                                   // 그렇지 않다면 cnt+count를 해주어 총 봉지의 수가 몇개인지 출력
		printf("%d\n", cnt+count);
	}

	return 0;
}