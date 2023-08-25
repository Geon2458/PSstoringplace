#include <stdio.h>

struct member{
	int age;
	char name[101];
};

// struct member에 대한 전역변수
struct member list_sorted[200001];

void merge(struct member *list, int left, int mid, int right);
void merge_sort(struct member *list, int left, int right);

int main(void){
	
	/*
	해결해야 하는 조건
	
	OJ member - n
	
	나이순, 가입순
	
	member age;
	member name[101];
	
	struct
	*/
	
	int n;
	
	// OJ member
	scanf("%d", &n);
	
	// member list
	struct member list[n];
	
	// age, name
	for (int i = 0; i < n; i++){
		scanf("%d %s", &list[i].age, list[i].name);
	}
	
	merge_sort(list, 0, n-1);
	
	for (int i = 0; i < n; i++){
		printf("%d %s\n", list[i].age, list[i].name);
	}
	
	return 0;
}

void merge(struct member *list, int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	// 구조체 정렬
	while (l<=mid && m<=right){
		
		if (list[l].age<=list[m].age){
			list_sorted[k++] = list[l++];
		}
		
		else{
			list_sorted[k++] = list[m++];
		}
	}
	
	while (l<=mid){
		list_sorted[k++] = list[l++];
	}
	while (m<=right){
		list_sorted[k++] = list[m++];
	}
	
	for (int i = left; i <= right; i++){
		list[i] = list_sorted[i];
	}
}

void merge_sort(struct member *list, int left, int right){
	
	int mid = (left+right)/2;
	
	if(left<right){
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}