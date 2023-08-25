#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	직사각형의 중앙을 찾아 중앙과 가깝지 않은 좌표를 기준으로 직사각형의 경계선과의 거리를 게산한다.
	
	직사각형의 중앙 = (w/2,h/2)
	
	(x,y) 중 어떤 숫자가 중앙과 가까운지 구별 후 제외
	*/
	
	int x, y, w, h, len, wid;                  // (한수의 좌표 x,y)  (세로 w len)  (가로 h wid)
	
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	int a = w/2;
	int b = h/2;

	if (a > x){                                // a가 x보다 크면 a-x가 양수
		len = a-x;
	}
	else{                                      // x가 a보다 크면 x-a가 양수
		len = x-a;
	}
	if (b > y){                                // b가 y보다 크면 b-y가 양수
		wid = b-y;
	}
	else{                                      // y가 b보다 크면 y-b가 양수
		wid = y-b;
	}
	
	if (len > wid){                            // 더 큰 쪽이 중앙보다 직사각형의 경계에 가까우므로
		if (x > a){                            // x가 크면 w좌표에 좀더 가까우기 때문
			len = w - x;
		}
		else {                                 // 반대의 경우 x가 0에 가깝기 때문
			len = x;
		}
		printf("%d\n", len);
	}
	else{                                     
		if (y > b){
			wid = h - y;
		}
		else {
			wid = y;
		}
		printf("%d\n", wid);
	}
	
	return 0;
}