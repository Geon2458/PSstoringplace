#include <stdio.h>

int main(void)
{
	char A[256];
	scanf("%s", A);
	printf("%s?\?!", A); // 삼중자(??!)로 인해 \ 추가
	
	return 0;
}