#include <stdio.h>
int sort[2000001];                                                      // 전역 변수

int main(void){
	
	/*
	해결해야 하는 조건
	
	합병? 병합? 정렬
	
	left mid mid+1 right
	*/
	
	void merge(int arr[], int left, int mid, int right);
	void merge_sort(int arr[], int left, int right);
	
	int arr[2000001];
	int n;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	merge_sort(arr, 0, n-1);                                              // 병합 정렬
	
	for (int j = 0; j < n; j++){
		printf("%d\n", arr[j]);
	}
	
	return 0;
}

void merge(int arr[], int left, int mid, int right){
	
	int l = left;
	int m = mid+1;
	int r = right;
	int k = left;
	
	while(l <= mid && m <= r){
		if (arr[l] <= arr[m]){
			sort[k++] = arr[l++];
		}
		else{
			sort[k++] = arr[m++];
		}
	}
	
	if (l > mid){
		for (int j = m; j <= r; j++){
			sort[k++] = arr[j];
		}
	}
	else{
		for (int i = l; i < m; i++){
			sort[k++] = arr[i];
		}
	}

	for (int i = left; i <= right; i++){
		arr[i] = sort[i];
	}
}

void merge_sort(int arr[], int left, int right){
	
	int mid = (left+right)/2;
	
	if (left < right){
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}