#include <stdio.h>
int x_sort[1000001];
int y_sort[1000001];

int main(void){

	/*
	해결해야 하는 조건
	
	2차원 평면 위의 점 n개
	(x,y)
	
	x1과 x2가 같다면 y비교
	
	1초
	*/
	void merge_sort(int *x, int *y, int left, int right);
	void merge(int *x, int *y, int left, int mid, int right);
	
	int n;
	int x[100001], y[100001];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	
	merge_sort(x, y, 0, n-1);
	
	for (int i = 0; i < n; i++){
		printf("%d %d\n", x[i], y[i]);
	}
	
}

void merge(int *x, int *y, int left, int mid, int right){
	
	int l = left;
	int m = mid+1;
	int r = right;
	int k = left;
	
	while(l <= mid && m <= r){
		
		if (x[l] < x[m] || (x[l] == x[m] && y[l] <= y[m])){           // 배열 x의 값이 같을 때 y를 비교
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
	
	
	if (l > mid){
		for (int j = m; j <= r; j++){
			x_sort[k] = x[j];
			y_sort[k] = y[j];
			k++;
		}
	}
	else{
		for (int i = l; i < m; i++){
			x_sort[k] = x[i];
			y_sort[k] = y[i];
			k++;
		}
	}

	for (int i = left; i <= right; i++){
		x[i] = x_sort[i];
		y[i] = y_sort[i];
	}
}

void merge_sort(int *x, int *y, int left, int right){
	
	int mid = (left+right)/2;
	
	if (left < right){
		// left
		merge_sort(x, y, left, mid);
		
		// right
		merge_sort(x, y, mid+1, right);
		
		// left mid right
		merge(x, y, left, mid, right);
	}
}