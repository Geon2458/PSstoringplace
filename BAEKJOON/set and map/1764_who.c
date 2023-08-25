#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char find[500001][21];
int cnt = 0;

char sorted[1000001][42];

struct bucket *hashTable = NULL;

struct Who{
	char heard[21];
	char seen[21];
	
	struct Who *next;
};

struct bucket{
	struct Who *head;
};

struct Who *createList(char *heard){
	struct Who *new;
	new = (struct Who*)malloc(sizeof(struct Who));
	
	strcpy(new->heard, heard);
	new->next = NULL;
	
	return new;
};

void insert(char *heard);
void search(char *seen);
void merge(char (**list), int left, int mid, int right);
void merge_sort(char (**list), int left, int right);

int main(void){
	
	/*
	해결해야 하는 조건
	
	n 명단 50만
	m 명단 50만
	
	이름 길이 20 이하
	
	strcmp
	hash
	merge_sort
	*/
	
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	hashTable = (struct bucket*)malloc(sizeof(struct bucket)*(n+m));
	
	struct Who *h = (struct Who*)malloc(sizeof(struct Who)*n);
	for (int i = 0; i < n; i++){
		scanf("%s", h[i].heard);
		insert(h[i].heard);
	}
	
	struct Who *s = (struct Who*)malloc(sizeof(struct Who)*m);
	for (int i = 0; i < m; i++){
		scanf("%s", s[i].seen);
		search(s[i].seen);
	}
	
	// list 2차원 배열 동적할당
	char **list;
	list = malloc(sizeof(char *)*cnt);
	for (int i = 0; i < cnt; i++){
		list[i] = malloc(sizeof(char)*21);
		strcpy(list[i], find[i]);
	}
	
	// 사전순으로 정렬
	merge_sort(list, 0, cnt-1);
	
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++){
		printf("%s\n", list[i]);
	}
	
	free(list);
	free(h);
	free(s);
	
	return 0;
}

unsigned long long hash(char *heard){
	unsigned long long hash = 5381;
	unsigned long long a;
	
	while (a = *heard++){
		hash = ((((hash<<5)+hash)+a)*'r')%5381;
	}
	
	return hash;
}

void insert(char *heard){
	int Index = hash(heard);
	struct Who *new = createList(heard);
	
	if (hashTable[Index].head == NULL){
		hashTable[Index].head = new;
	}
	else{
		new->next = hashTable[Index].head;
		hashTable[Index].head = new;
	}
	
	return;
}

void search(char *seen){
	int Index = hash(seen);
	struct Who *who = hashTable[Index].head;
	
	while (who != NULL){
		if (strcmp(who->heard, seen)==0){
			strcpy(find[cnt++], who->heard);
		}
		who = who->next;
	}
	
	return;
}

void merge(char (**list), int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	while (l<=mid && m<=right){
		if (strcmp(list[l], list[m])>0){
			strcpy(sorted[k++], list[m++]);
		}
		else{
			strcpy(sorted[k++], list[l++]);
		}
	}
	
	while(l<=mid){
		strcpy(sorted[k++], list[l++]);
	}
	while(m<=right){
		strcpy(sorted[k++], list[m++]);
	}
	
	for (int i = left; i <= right; i++){
		strcpy(list[i], sorted[i]);
	}
}

void merge_sort(char (**list), int left, int right){
	int mid = (left+right)/2;
	
	if (left<right){
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}