#include <stdio.h>

int n_sorted[1000001];

void merge(int *n_num, int left, int mid, int right);
void merge_sort(int *n_num, int left, int right);
int binsearch (int *n_num, int N, int n);

int main(void){
	
	/*
	해결해야 하는 조건
	
	n <= 500,000 50만
	m <= 500,000 50만
	
	n == m -> '1' 출력
	n != m -> '0' 출력
	
	중복수 X
	
	binary search 이진 검색
	*/
	
	int n, m;
	int n_num[500001];
	int m_num[500001];
	int index;
	
	// 숫자 카드
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &n_num[i]);
	}
	
	// 정수
	scanf("%d", &m);
	for (int j = 0; j < m; j++){
		scanf("%d", &m_num[j]);
	}
	
	// 이진 검색을 위해 n_num을 정렬
	merge_sort(n_num, 0, n-1);
	
	// 이진 검색을 이용하여 비교 후 출력
	for (int i = 0; i < m; i++){
		binsearch(n_num, n, m_num[i]);
	}
	
	return 0;
}

int binsearch (int *n_num, int N, int n){
	int low;
	int high;
	int mid;
	
	low  = 0;
	high = N-1;
	
	while (low<=high){
		mid = (low+high)/2;
		
		if (n == n_num[mid]){
			printf("1 ");
			break;
		}
		else if (n < n_num[mid]){
			high = mid -1;
		}
		else if (n > n_num[mid]){
			low  = mid +1;
		}
	}
	if (low > high){
		printf("0 ");
	}
}

void merge(int *n_num, int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	while (l<=mid && m<=right){
		if (n_num[l]<=n_num[m]){
			n_sorted[k++] = n_num[l++];
		}
		else{
			n_sorted[k++] = n_num[m++];
		}
	}
	
	while (l<=mid){
		n_sorted[k++] = n_num[l++];
	}
	while (m<=right){
		n_sorted[k++] = n_num[m++];
	}
	
	for (int i = left; i <= right; i++){
		n_num[i] = n_sorted[i];
	}
}

void merge_sort(int *n_num, int left, int right){
	
	int mid = (left+right)/2;
	
	if (left<right){
		merge_sort(n_num, left, mid);
		merge_sort(n_num, mid+1, right);
		merge(n_num, left, mid, right);
	}
}