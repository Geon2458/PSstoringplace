#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	n == sum += n의 약수들
	
	이중 반복문을 사용하여 약수와 +를 번갈아 printf
	
	n의 약수를 저장할 배열 fac와 몇 번 반복할 것인지를 위한 cnt = 0;
	
	n == -1 프로그램 종료
	*/
	
	int n;
	int fac[101];
	
	while(1){
		scanf("%d", &n);
		int sum = 0, cnt = 0;                  // 한번 되돌아 올 때마다 sum과 cnt를 0으로 초기화
		if (n == -1){                          // n == -1 이면 프로그램 종료
			exit(0);
		}
		for (int i = n; i > 1; i--){           // n은 더하지 않을 것이기 때문에  n-1
			if (n%i == 0){                     // 나머지가 0 이면 나누어 떨어지는 숫자 이므로
				cnt++;                         // 약수의 개수를 cnt
				sum += n/i;                    // 완전수인지 파악하기 위해 약수를 모두 더함
				fac[cnt] = n/i;
			}
		}
		if (n == sum){                         // n과 sum 이 같으면 완전수 이므로
			printf("%d = ", n);
			for (int k = 1; k <= cnt; k++){    // 배열 fac에 숫자들이 내림 차순으로 저장 되어 있으므로
				printf("%d", fac[k]);
				for (int l = k; l <= k; l++){  // 이중 반복문을 사용하여 숫자와 숫자 사이에 + 출력
					if (k == cnt){             // 배열 fac == cnt 이후에 + 가 출력이 되는 것을 막기 위해서
						break;
					}
					printf(" + ");
				}
			}
		}
		else{
			printf("%d is NOT perfect.", n);   // 완전수가 아닐 시 n is NOT perfect. 출력
		}
		printf("\n");
	}
	
	return 0;
}