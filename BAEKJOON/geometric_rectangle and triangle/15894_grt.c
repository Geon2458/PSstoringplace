#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	n*4를 해야하지만 n은 10^9(10억)까지 넣을 수 있기 때문에 
	int 형이 아닌 더 큰 범위인 long을 사용해 주어야 한다.
	*/
	
	long a;
	
	scanf("%ld", &a);
	
	printf("%ld", a*4);

	return 0;
}