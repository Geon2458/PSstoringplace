#include <stdio.h>
#include <string.h>

char s_sorted[20001][501];
int cnt = 0;

void merge(char (*s)[501], int left, int mid, int right);
void merge_sort(char (*s)[501], int left, int right);
int binsearch(char (*s)[501], int N, char *n);

int main(void){
	
	/*
	해결해야 하는 조건
	
	n개의 문자열로 이루어진 집합 s
	
	m개의 문자열 중에 집합 s에 포함되어 있는 것이 몇개? -> cnt++
	
	strcmp사용하여 비교
	*/
	
	int n, m;
	
	// n개의 문자열로 이루어진 집합 s
	scanf("%d %d", &n, &m);
	char s[n][501];
	char m_s[m][501];
	
	for (int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}
	
	for (int j = 0; j < m; j++){
		scanf("%s", m_s[j]);
	}
	
	merge_sort(s, 0, n-1);
	
	// 이진검색 strcmp 사용
	for (int i = 0; i < m; i++){
		binsearch(s, n, m_s[i]);
	}
	
	printf("%d\n", cnt);
	
	return 0;
}

int binsearch(char (*s)[501], int N, char *n){
	int low  = 0;
	int high = N-1;
	
	while(low <= high){
		
		int mid = (low+high)/2;
		
		if (strcmp(n, s[mid]) == 0){
			cnt++;
			break;
		}
		else if (strcmp(n, s[mid]) < 0){
			high = mid -1;
		}
		else if (strcmp(n, s[mid]) > 0){
			low = mid +1;
		}
	}
}

// 단어 길이순 정렬
void merge(char (*s)[501], int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	while(l<=mid && m<=right){
		if(strcmp(s[l], s[m]) > 0){
			strcpy(s_sorted[k++], s[m++]);
		}
		else{
			strcpy(s_sorted[k++], s[l++]);
		}
	}
	
	while(l<=mid){
		strcpy(s_sorted[k++], s[l++]);
	}
	while(m<=right){
		strcpy(s_sorted[k++], s[m++]);
	}
	
	for (int i = left; i <= right; i++){
		strcpy(s[i], s_sorted[i]);
	}
}

void merge_sort(char (*s)[501], int left, int right){
	
	int mid = (left+right)/2;
	
	if (left < right){
		merge_sort(s, left, mid);
		merge_sort(s, mid+1, right);
		merge(s, left, mid, right);
	}
}