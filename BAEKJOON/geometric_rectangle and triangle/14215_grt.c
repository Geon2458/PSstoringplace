#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	세 변의 길이가 모두 같은 경우
	
	두 변의 길이가 같고 두 변의 길이의 합이 가장 긴 변의 길이보다 '같거나 짧은' 경우
	
	세 변의 길이가 모두 다른 경우 중 두 변의 길이의 합이 가장 긴 변의 길이보다 긴 경우
	
	세 변의 길이가 모두 다른 경우 중 두 변의 길이의 합이 가장 긴 변의 길이보다 짧은 경우
	*/
	
	int sum = 0;
	int t[3];
	
	for (int i = 0; i < 3; i++){                 // 세 변의 길이를 배열 t에 저장          
		scanf("%d", &t[i]);
	}
	
	int max = t[0];
	for (int i = 0; i < 3; i++){                 // 가장 긴 변의 길이 구하기
		if (max < t[i]){
			max = t[i];
		}
		sum += t[i];
	}
	
	int sm = sum - max;
	if (t[0] == t[1] && t[1] == t[2]){           // 세 변의 길이가 모두 같을 경우
		printf("%d\n", sum);
	}
	else if (t[0] == t[1] && sm <= max
		  || t[1] == t[2] && sm <= max
		  || t[2] == t[0] && sm <= max){         // 두 변의 길이가 같고 두 변의 길이의 합이 가장 긴 변의 길이보다 같거나 짧은 경우
		max = sum - max - 1;                     // 가장 긴 변의 길이인 max의 값을 다른 두 변의 합에서 -1하여 저장
		printf("%d\n", sm+max);
	}
	else if (sm > max){                          // 세 변의 길이가 모두 다른 경우 중 두 변의 길이의 합이 가장 긴 변의 길이보다 긴 경우
		printf("%d\n", sum);
	}
	else{                                        // 세 변의 길이가 모두 다른 경우 중 두 변의 길이의 합이 가장 긴 변의 길이보다 짧은 경우
		max = sum - max - 1;                     // 가장 긴 변의 길이인 max의 값을 다른 두 변의 합에서 -1하여 저장
		printf("%d\n", sm+max);
	}
	
	return 0;
}