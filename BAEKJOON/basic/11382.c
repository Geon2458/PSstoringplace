#include <stdio.h>

int main(void)
{
	long a, b, c;  // 범위가 10^12 까지 이기 때문에 int형 안에 모두 넣기엔 부족함.
	
	scanf("%ld %ld %ld", &a, &b, &c);
	
	printf("%ld", a+b+c);
	
	return 0;
}