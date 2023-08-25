#include <stdio.h>
int arr[10001] = {0};

int main(void){
	
	/*
	해결해야 하는 조건
	
	카운팅 정렬
	
	주어진 배열의 값 범위가 작은 경우 빠른 속도를 갖는 정렬 알고리즘
	
	최댓값과 입력 배열의 원소 값 개수를 누적합으로 구성한 배열로 정렬을 수행한다
	*/
	
	int n, num;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d", &num);                          // 입력할 수들
		arr[num] += 1;                              // 같은 숫자는 +1
	}
	
	for (int i = 0; i < 10001; i++){
		for (int j = 0; j < arr[i]; j++){           // 0 부터 arr[i]까지 i가 몇 번 입력 되었는지 출력
			printf("%d\n", i);
		}
	}
	
	return 0;
}