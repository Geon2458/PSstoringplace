#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	n의 약수는 무엇? 8 -> 1, 2, 4, 8
	
	n의 약수 중 k번째로 작은 수는? -> cnt = 0사용
	
	약수가 없을 시 0 출력
	*/
	
	int n, k, cnt = 0;
	int fac[101];
	
	scanf("%d %d", &n, &k);
	
	for (int i = n; i > 0; i--){
		if (n%i == 0){
			cnt++;
			if (cnt == k){
				printf("%d\n", n/i);
				break;
			}
		}
	}
	if (cnt < k){
		printf("0\n");
	}
	
	return 0;
}