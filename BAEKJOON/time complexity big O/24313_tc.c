#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	f(n) <= g(n)*c
	-> a*n+b <= c*n a <= c
	a b c n   -> |a|(x) -> -100 <= ai <= 100  
	
	f = a*n+b
	g = n
	c = c
	n0 = n
	*/
	
	int a, b, c, n;
	
	scanf("%d %d %d %d", &a, &b, &c, &n);

	int f = a*n+b;
	int g = n;                             // n0의 최솟값이 n과 같기 때문에 n0값은 따로 넣지 않는다
	
	if (f <= g*c && a <= c){                // f의 값이 n0의 최솟값인 n이 들어 갔을 때의 값보다 작아거나 같아야 하고 a > c 면 f <= g 성립이 안되기 때문
		printf("1\n");
	}
	else{
		printf("0\n");
	}
	
	return 0;
}