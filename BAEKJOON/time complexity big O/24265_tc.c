#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	big O 표기법 - 시간 복잡도
	
	MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 1
        for j <- i + 1 to n
            sum <- sum + A[i] × A[j]; # 코드1
    return sum;
	
	n = 7
	i     1        2        3        4        5        6
	j   2 ~ 7    3 ~ 7    4 ~ 7    5 ~ 7    6 ~ 7    7 ~ 7
	sum   6        5        4        3        2        1
	
	등차수열 1~n 까지의 합 n*(n+1)/2   ex) 6*7/2
	
	이 문제에서는 scanf("%d", &n); -> 1~n-1 까지의 합
	
	n*(n-1)/2                      ex) 7*6/2
	}
	*/
	long n;
	
	scanf("%ld", &n);
	
	printf("%ld\n2\n", n*(n-1)/2);
	
	return 0;
}