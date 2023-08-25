#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int a, b;
	
	/*
	해결해야 하는 조건
	
	a는 b의 배수 or 약수? a != b
	
	a == 0 && b == 0이면 프로그램 종료
	*/
	
	while(1){
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0){            // 0 0  입력 시 프로그램 종료
			exit(0);
		}
		if (b%a == 0){
			printf("factor\n");            // 약수
		}
		else if (a%b == 0){
			printf("multiple\n");          // 배수
		}
		else{
			printf("neither\n");           // 어느 것도 아닌
		}
	}
	
	return 0;
}