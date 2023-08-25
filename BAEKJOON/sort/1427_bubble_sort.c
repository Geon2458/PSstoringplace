#include <stdio.h>
#include <string.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	n의 크기 10억
	
	내림차순
	
	중복된 수
	*/
	
	int cnt = 0;
	char sort[11];
	
	scanf("%s", sort);
	
	int s = strlen(sort);
	
	while(cnt < s){
		for (int i = cnt; i < s-1; i++){           // 각 점수들을 내림차순으로 저장
			if (sort[cnt] <= sort[i+1]){
				int swap   = sort[cnt];
				sort[cnt]  = sort[i+1];
				sort[i+1]  = swap;
			}
		}
		cnt++;
	}
	
	for (int i = 0; i < s; i++){
		printf("%d", sort[i]%48);
	}
	
	return 0;
}