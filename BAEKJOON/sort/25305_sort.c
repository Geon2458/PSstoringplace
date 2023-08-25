#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	응시자 수 n명
	수상자 수 k명
	
	n명의 점수들을 입력 받은 후 내림차순 정렬
	k-1번 째 배열의 점수 출력
	*/
	
	int n, k, cnt = 0;
	int sort[1001];
	
	scanf("%d %d", &n, &k);                        // 응시자 n, 수상자 k
	
	for (int i = 0; i < n; i++){
		scanf("%d", &sort[i]);
	}
	while(cnt < n-1){
		for (int i = cnt; i < n-1; i++){           // 각 점수들을 내림차순으로 저장
			if (sort[cnt] <= sort[i+1]){
				int swap   = sort[cnt];
				sort[cnt]  = sort[i+1];
				sort[i+1]  = swap;
			}
		}
		cnt++;
	}
	
	printf("%d\n", sort[k-1]);
	
	return 0;
}