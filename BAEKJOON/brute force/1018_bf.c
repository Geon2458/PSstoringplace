#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	m = 세로 n = 가로
	
	B -> != W  cnt++

	
	W -> != B  count++
	
	
	8×8 크기의 체스판
	
	*/
	
	int n, m, min = 32;
	char WB[52][52] = {0,};
	char chessboard1[8][8] = {                              // 체스판이 될 수 있는 2가지 경우
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'}
	};
	char chessboard2[8][8] = {
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'}
	};
	
	
	scanf("%d %d", &m, &n);
	
	for (int i = 0; i < m; i++){
		scanf("%s", WB[i]);
	}
	for (int i = 0; i < m-7; i++){                            // 세로 +1
		for (int j = 0; j < n-7; j++){                        // 가로부터 한 칸씩 +1
			int cnt = 0, count = 0;
			for (int k = i; k < i+8; k++){                    // 세로
				for (int l = j; l < j+8; l++){                // 가로
					if (chessboard1[k-i][l-j] != WB[k][l]){
						cnt++;
					}
					if (chessboard2[k-i][l-j] != WB[k][l]){
						count++;
					}
				}
			}
			if (cnt <= count){                                // cnt가 더 작을 경우 바꾸는 횟수가 더 적다는 뜻 이므로
				if(min >= cnt){
					min = cnt;
				}
			}
			else if (cnt > count){                            // count가 더 작을 경우 위와 같은 의미 이므로
				if (min >= count){
					min = count;
				}
			}
		}
	}

	printf("%d\n", min);                                      // 최솟값이 저장되어 있는 min출력
	
	return 0;
}