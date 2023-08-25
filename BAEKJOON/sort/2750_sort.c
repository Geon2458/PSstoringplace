#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	입력한 수를 오름차순으로 저장 후 출력
	
	while문으로 최솟값 계속 찾아 정렬?
	-> swap?
	-> 언제까지 반복?
	*/
	
	int n, cnt = 0;
	int sort[1001];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &sort[i]);
	}
	while(cnt < n-1){
		for (int i = cnt; i < n-1; i++){             // 'i == n-1일 때 sort[n]와 swap 방지'
			if (sort[cnt] >= sort[i+1]){
				int swap   = sort[cnt];
				sort[cnt]  = sort[i+1];
				sort[i+1]  = swap;
			}
		}
		cnt++;
	}
	for (int i = 0; i < n; i++){
		printf("%d\n", sort[i]);
	}
	
	return 0;
}