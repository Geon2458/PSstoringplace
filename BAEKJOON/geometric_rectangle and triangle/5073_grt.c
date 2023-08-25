#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	세 변의 길이가 모두 같은 경우 Equilateral
	두 변의 길이만 같은 경우 Isosceles
	각 변의 길이가 모두 다른 경우 Scalene
	가장 긴 변의 길이가 나머지 두 변의 길이의 합보다 같거나 작은 경우 Invalid
	
	모두 더한 값에서 최댓값을 뺀 값이 최댓값 보다 작을 경우 -> Invalid
	
	0 0 0 입력시 프로그램 종료
	*/
	
	int t[3];                                                       // 세 변의 길이를 저장할 배열 t(triangle)
	
	while(1){
		int sum = 0;                                                // 세 변의 길이를 모두 더할 때 사용
		
		for (int i = 0; i < 3; i++){                                // 세 변의 길이를 배열 t에 저장
			scanf("%d", &t[i]);
		}
		
		int max = t[0];                               	            // 최댓값을 구하기 위해 사용
		for (int i = 0; i < 3; i++)
		{
			if (max < t[i]) 
			{
				max = t[i];
			}
			sum += t[i];                                            // 세 변의 길이를 모두 더함
		}
		if (sum == 0){                                              // 0 0 0 입력 시 sum의 값도 0 이므로
			exit(0);                                                // while문 종료
		}
		else if (sum - max <= max){                                 // 두 변의 합이 가장 긴 변의 길이보다 작을 경우
			printf("Invalid\n");
		}
		else if (t[0] == t[1] && t[1] == t[2]){                     // 세 변의 길이가 모두 같은 경우
			printf("Equilateral\n");
		}
		else if (t[0] != t[1] && t[1] != t[2] && t[2] != t[0]){     // 세 변의 길이가 모두 다른 경우
			printf("Scalene\n");
		}
		else{                                                       // 두 변의 길이만 같은 경우
			printf("Isosceles\n");
		}
	}
	
	return 0;
}