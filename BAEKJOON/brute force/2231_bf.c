#include <stdio.h>
#include <string.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	분해합
	256 = 245+2+4+5
	
	분해..
	
	n입력 -> 어떤 수를 분해합 시켜야 n?
	
	생성자가 없을 경우 0 출력
	*/
	
	int n, count = 0;
	int M[101];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){                                                                // 0부터 n까지 분해합
		int m = i + (i/100000) + (i/10000)%10 + (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10;    // 생성자 + 분해된 수를 m에 저장
		if (m == n){                                                                            // m과 n이 같다면
			count++;                                                                            // count++
			M[count] = i;                                                                       // 배열 M에 생성자를 순서대로 저장
		}
	}
	
	if (count == 0){                                                                             // 생성자가 없을 경우 0 출력
		printf("0\n");
	}
	else{
		printf("%d\n", M[1]);                                                                     // 가장 작은 생성자는 맨 처음 저장된 수 이므로 M[1] 출력
	}
	
	return 0;
}