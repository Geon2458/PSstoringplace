#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	버블 정렬
	
	평균값과 중앙값
	
	/5 오름차순 후 sort[2]
	*/
	
	int sort[5], cnt = 0;
	
	for (int i = 0; i < 5; i++){
		scanf("%d", &sort[i]);
	}
	while(cnt < 4){
		for (int i = cnt; i < 4; i++){             // i==4일 때 sort[5]와 swap 방지
			if (sort[cnt] >= sort[i+1])}
				int swap   = sort[cnt];
				sort[cnt]  = sort[i+1];
				sort[i+1]  = swap;
			}
		}
		cnt++;
	}
	
	int average = 0;                               // 평균
	for (int i = 0; i < 5; i++){
		average += sort[i];                        // 평균값을 구하기 위해 모두 더함
	}
	
	printf("%d\n%d\n", average/5, sort[2]);        // 평균값과 중앙값 출력
	
	return 0;
}