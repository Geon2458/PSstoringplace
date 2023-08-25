#include <stdio.h>
#include <stdlib.h>

int sorted[1000000];

void merge(int *num1, int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	while (l<=mid&&m<=right){
		if (num1[l]<num1[m]){
			sorted[k++] = num1[l++];
		}
		else{
			sorted[k++] = num1[m++];
		}
	}
	
	while (l<=mid){
		sorted[k++] = num1[l++];
	}
	while (m<=right){
		sorted[k++] = num1[m++];
	}
	
	for (int i = left; i <= right; i++){
		num1[i] = sorted[i];
	}
}

void merge_sort(int *num1, int left, int right){
	int mid = (left+right)/2;
	
	if (left<right){
		merge_sort(num1, left, mid);
		merge_sort(num1, mid+1, right);
		merge(num1, left, mid, right);
	}
}

int lower_bound(int *num1, int num2, int size){
	int lower = -1;
	int start = 0;
	int end = size-1;
	
	while (end>=start){
		int mid = (start+end)/2;
		
		if (num1[mid]>=num2){
			lower = mid;
			end   = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	
	return lower;
}

int upper_bound(int *num1, int num2, int size){
	int upper = -1;
	int start = 0;
	int end = size-1;
	
	while (end>=start){
		int mid = (start+end)/2;
		
		if (num1[mid]<=num2){
			upper = mid;
			start = mid+1;
		}
		else{
			end   = mid-1;
		}
	}
	
	return upper;
}

int main(void){
	
	/*
	해결해야 하는 조건
	
	n 50만
	m 50만
	
	card_m에 card_n이 몇개?
	
	정렬
	이분 탐색(lower_bound, upper_bound)
	*/
	
	int n, m;
	
	scanf("%d", &n);
	// num1 크기
	int *num1 = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		scanf("%d", &num1[i]);
	}
	
	scanf("%d", &m);
	// num2 크기
	int *num2 = (int*)malloc(sizeof(int)*m);
	for (int i = 0; i < m; i++){
		scanf("%d", &num2[i]);
	}
	
	// lower_bound, upper_bound 사용을 위해 정렬
	merge_sort(num1, 0, n-1);
	
	// lower_bound, upper_bound 사용
	int lower = 0;
	int upper = 0;
	for (int i = 0; i < m; i++){
		lower = lower_bound(num1, num2[i], n);
		upper = upper_bound(num1, num2[i], n);
		// -1이 나올 시 0 출력
		if (lower == -1 || upper == -1){
			printf("0 ");
			continue;
		}
		
		// end부터 몇 번째 - start부터 몇 번째
		else{
			printf("%d ", upper - lower+1);
		}
	}
	
	return 0;	
}