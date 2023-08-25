#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	big O 표기법 - 시간 복잡도
	
	MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        sum <- sum + A[i]; # 코드1
    return sum;
	}
	
	#코드1의 수행 횟수는 n의 값 만큼 for문이 반복한다.
	
	그렇기 때문에 수행 횟수는 항상 n로 일정하므로 -> 빅오 표기법 O(n) -> 최고차항은 항상 1이다.
	*/
	
	int n;
	
	scanf("%d", &n);
	
	printf("%d\n1\n", n);
	
	return 0;
}