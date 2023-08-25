#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	(x,y) 좌표중 
	제일 큰 x좌표 - 제일 작은 x좌표
	제일 큰 y좌표 - 제일 작은 y좌표
	
	최댓값 최솟값 구하기  n = 1이면 0 출력
	*/
	
	int n, x, y;
	int xrr[1000000], yrr[1000000];
	
	scanf("%d", &n);
	
	if (n == 1){                   // n == 1이면 직사각형을 만들 수 없으므로
		printf("0\n");
	}
	else{
		for (int i = 0; i < n; i++){   // 각각의 x좌표와 y좌표를 저장
			scanf("%d %d", &x, &y);
			xrr[i] = x;
			yrr[i] = y;
		}
		
		int mx = xrr[0], my = yrr[0];   // x의 최댓값 mx, y의 최댓값 my
		for (int i = 0; i < n; i++){
			if (mx < xrr[i]){
				mx = xrr[i];
			}
			if (my < yrr[i]){
				my = yrr[i];
			}
		}
		
		int nx = xrr[0], ny = yrr[0];   // x의 최솟값 nx, y의 최솟값 ny         
		for (int i = 0; i < n; i++){
			if (nx > xrr[i]){
				nx = xrr[i];
			}
			if (ny > yrr[i]){
				ny = yrr[i];
			}
		}
		printf("%d\n", (mx-nx)*(my-ny)); // 넓이를 구하기 위해 x와 y의 (최댓값 - 최솟값) 후 x*y
	}
	
	
	return 0;
}