#include <stdio.h>

int x_sorted[2000001];
int x_press[1000001];

void merge(int *x, int left, int mid, int right);
void merge_sort(int *x, int left, int right);
int binsearch(int *x_press, int N, int n);

int main(void){
	
	/*
	해결해야 하는 조건
	
	좌표 압축 알고리즘(coordinate compression)
	-> 주어진 수들의 값이 아닌, 크기 순서만이 문제 해결에 필요한 경우
	   좌표 압축을 해줄 수 있다
	
	1. 배열 a를 정렬한 새로운 배열 b를 만듦
	2. 필요 시 중복된 원소들을 제거
	3. 각 a[i]를 b[]에서 이분탐색하여 인덱스를 계산
	
	시간복잡도 O(nlogn)
	*/
	
	int n, cnt = 0;
	int x[1000001];
	int xb[1000001];
	int index;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d", &x[i]);
		xb[i] = x[i];
	}
	
	merge_sort(x, 0, n-1);
	
	// x_press에 중복된 수를 빼고 저장
	for (int i = 0; i < n; i++){
		if (x[i] == x[i+1]){
			continue;
		}
		x_press[cnt++] = x[i];
	}

	for (int i = 0; i < n; i++){
		index = binsearch(x_press, cnt, xb[i]);
		printf("%d ", index);
	}
	
	return 0;
}

void merge(int *x, int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	while(l<=mid && m<=right){
		if (x[l] <= x[m]){
			x_sorted[k++] = x[l++];
		}
		else{
			x_sorted[k++] = x[m++];
		}
	}
	
	while(l<=mid){
		x_sorted[k++] = x[l++];
	}
	while(m<=right){
		x_sorted[k++] = x[m++];
	}
	
	for (int i = left; i <= right; i++){
		x[i] = x_sorted[i];
	}
}

void merge_sort(int *x, int left, int right){
	
	int mid = (left+right)/2;
	
	if (left<right){
		merge_sort(x, left, mid);
		merge_sort(x, mid+1, right);
		merge(x, left, mid, right);
	}
}

// 이진 탐색(binary search)
int binsearch(int *x_press, int N, int n){
    int low;
	int high;
    int mid;
 
    low = 0;
    high = N-1;
	
    while (low <= high){
		mid = (low + high)/2;
		
		if (n == x_press[mid]){
			return mid;     
		}
		else if (n < x_press[mid]){
			high = mid - 1;
		}
		else if (n > x_press[mid]){
			low = mid + 1;
		}
	}
}