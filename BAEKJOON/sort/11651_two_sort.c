#include <stdio.h>
int x_sort[1000001];
int y_sort[1000001];

int main(void){
	/*
	해결해야 하는 조건
	
	y오름차순
	
	y가 같다면 x비교
	
	2개의 좌표 병합정렬
	*/
	
	void merge_sort(int *x, int *y, int left, int right);
	void merge(int *x, int *y, int left, int mid, int right);
	
	// 점의 개수
	int n;
	// 좌표 x, y
	int x[100001], y[100001];
	
	// 점의 개수 입력
	scanf("%d", &n);
	
	// 점의 개수 만큼 배열 x,y에 값 입력
	for (int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	
	// 정렬이 완료된 merge_sort
	merge_sort (x, y, 0, n-1);
	
	// 정렬된 배열 x, y를 출력
	for (int j = 0; j < n; j++){
		printf("%d %d\n", x[j], y[j]);
	}
	
	return 0;
}

// 정복 (conquer)
void merge(int *x, int *y, int left, int mid, int right){

	int l = left;
	int m = mid+1;
	int k = left;       // x_sort와 y_sort 배열에 사용
	int r = right;
	
	// left ~ mid mid+1 ~ right
	while(l <= mid && m <= r){
		// y오름차순 y가 같다면 x비교
		if (y[l] < y[m] || y[l] == y[m] && x[l] <= x[m]){
			x_sort[k] = x[l];
			y_sort[k] = y[l];
			k++, l++;
		}
		
		else{
			x_sort[k] = x[m];
			y_sort[k] = y[m];
			k++, m++;
		}
	}
	
	// left ~ mid 안에서 비교 
	if (l <= mid){
		for (int i = l; i < m; i++){
			x_sort[k] = x[i];
			y_sort[k] = y[i];
			k++;
		}
	}
	// mid+1 ~ right 안에서 비교
	else{
		for (int j = m; j <= r; j++){
			x_sort[k] = x[j];
			y_sort[k] = y[j];
			k++;
		}
	}
	
	// 모두 정렬이 되었다면 x와 y에 입력
	for (int i = left; i <= right; i++){
		x[i] = x_sort[i];
		y[i] = y_sort[i];
	}
}

// 분할 (divide)
void merge_sort(int *x, int *y, int left, int right){
	
	// mid 값 overflow 방지
	int mid = left + (right-left)/2;
	
	// left 값이 right 값보다 작을 시 실행
	if (left < right){
		// left
		merge_sort(x, y, left, mid);
		
		// right
		merge_sort(x, y, mid+1, right);
		
		// left ~ right
		merge(x, y, left, mid, right);
	}
}
