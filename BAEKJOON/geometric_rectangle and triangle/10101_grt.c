#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	세각이 같으면 Equilateral       정삼각형(등변)
	
	두각만 같으면 Isosceles         이등변 삼각형(이등변)
	
	어느 각도 같지 않으면 Scalene     삼각형(불균형)
	
	내각의 합이 180이 아니면 Error
	*/
	
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if (a==b && a==c && a==60){                           // 세 각의 크기가 모두 같고 각의 크기가 60인 경우
		printf("Equilateral\n");
	}
	else if (a!=b && b!=c && a!=c && a+b+c == 180){       // 세 각의 크기가 모두 다르고 내각의 합이 180인 경우 
		printf("Scalene\n");
	}
	else if (a+b+c != 180){                               // 내각의 합이 180이 아닌 경우
		printf("Error\n");
	}
	else {                                                // 그 외의 모든 경우(두 각의 크기만 같고 다른 한 각의 크기는 다르며 내각의 합이 180인 경우)
		printf("Isosceles\n");
	}
	
	return 0;
}