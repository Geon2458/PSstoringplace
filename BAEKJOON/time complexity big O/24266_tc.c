#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	big O 표기법 - 시간 복잡도
	
	MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        for j <- 1 to n
            for k <- 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
    }
	
	# 코드1의 수행 횟수는 n^3의 값 만큼 for문이 반복한다.
	
	그렇기 때문에 수행 횟수는 항상 n로 일정하므로 -> 빅오 표기법 O(n^3) -> 최고차항은 항상 3이다.
	*/
	
	long n;                    // n의 범위가 1 ≤ n ≤ 500,000이므로 n^3은 int 형 범위를 벗어 나기 때문에 long을 사용
	
	scanf("%ld", &n);
	
	printf("%ld\n3\n", n*n*n);
	
	return 0;
}