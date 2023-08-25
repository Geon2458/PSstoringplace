#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 2
        for j <- i + 1 to n - 1
            for k <- j + 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
	}
	
	n = 7
	i     1        2        3        4        5
	j   2 ~ 6    3 ~ 6    4 ~ 6    5 ~ 6    6 ~ 6
	k   5 * 5    4 * 4    3 * 3    2 * 2    1 * 1
	sum 5 + 25   4 + 16   3 + 9    2 + 4    1 + 1
	      30       20       12       6        2
	
	등차수열
	
	n*(n-1)*(n-2)/6    n^3
	*/
	long n;
	
	scanf("%ld", &n);
	
	printf("%ld\n3\n", n*(n-1)*(n-2)/6);
	
	return 0;
}