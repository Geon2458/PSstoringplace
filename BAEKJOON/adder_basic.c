#include <stdio.h>

/* 계산기 */

int main(void){
	
	int x, y;
	char Operator;

	scanf("%d %c %d", &x, &Operator, &y);

	if (Operator == '+'){
		printf("%d", x+y);
	}
	if (Operator == '-'){
		printf("%d", x-y);
	}
	if (Operator == '*'){
		printf("%d", x*y);
	}
	if (Operator == '/'){
		printf("%d", x/y);
	}
	if (Operator == '%'){
		printf("%d", x%y);
	}
	
	return 0;
}
