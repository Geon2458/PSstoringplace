#include <stdio.h>
#include <string.h>

int main(void){
	
	char num1[10001] = {0};              // 10^10001 1만자리
	char num2[10001] = {0};
	int str;                             // 자릿수가 큰 숫자를 저장
	
	scanf("%s %s", num1, num2);
	
	/*
	해결해야 하는 조건
	
	input 17 18
	output 2 13
	answer 33
	
	input 12 1
	output 2 2
	answer 13
	
	시간 복잡도 데이터 크기
	*/
	
	int s1 = strlen(num1);
	int s2 = strlen(num2);
	
	if (s1 > s2){                        // 글자수가 적은 숫자를 바꿔야 하므로
		int n = s1 - s2;                 // 글자수 차이를 n에 저장
		str = s1;
		for (int i = s2-1; i >= 0; i--){ // 뒷자리 숫자부터 n만큼 뒤로 보냄.. 1 2 3 4 5 0 0 -> 1 2 1 2 3 4 5
			num2[i+n] = num2[i];
		}
		for (int j = 0; j < n; j++){
			num2[j] = '\0';              // 뒤로 숫자를 보낸 만큼 앞에 '\0'을 해줌으로서 앞을 비움...1 2 1 2 3 4 5 -> 0 0 1 2 3 4 5 
		}
	}
	else if (s1 < s2){
		int n = s2 - s1;
		str = s2;
		for (int i = s1-1; i >= 0; i--){
			num1[i+n] = num1[i];
		}
		for (int j = 0; j < n; j++){
			num1[j] = '\0';
		}
	}
	else {
		str = s1;
		int n = 0;                        // 자릿 수가 같을 시 n = 0
	}
	
	for (int j = str-1; j > 0; j--){      // 뒷자리 숫자부터 계산
		if ((num1[j]+num2[j])%48 >= 10){
			num1[j-1] = num1[j-1]+1;
			num1[j] = num1[j]-10;
		}
	}
	
	for (int j = 0; j < str; j++){
		printf("%d", (num1[j]+num2[j])%48);
	}
	
	return 0;
}