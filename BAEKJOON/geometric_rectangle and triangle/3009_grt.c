#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	남은 좌표는 무엇인가?
	
	평행을 이용
	*/
	
	int a,b , c,d , e,f , g,h;                             // (a,b) , (c,d) , (e,f) , (g,h)
	
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	
	if (a==c){                                             // a와 c가 평행하면 g는 e와 평행이다.
		g = e;
	}
	else if (a==e){                                        // a와 e가 평행하면 g는 c와 평행하다.
		g = c;
	}
	else{
		g = a;
	}
	
	if (f==b){                                             // f와 b가 평행하면 h는 d와 평행하다.
		h = d;
	}
	else if (b==d){                                        // b와 d가 평행하면 h는 f와 평행하다.
		h = f;
	}
	else{
		h = b;
	}
	
	printf("%d %d", g, h);	
	
	return 0;
}