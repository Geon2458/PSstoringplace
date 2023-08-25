#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char login[2000001][6];
char sorted[2000001][6];
int c = 0;

// hash
struct bucket *hashTable = NULL;

int SIZE = 1000001;

struct list{
	char name[6];
	char log[6];
	
	// nextList
	struct list *next;
};

struct bucket{
	// headList
	struct list *head;
	// 몇 개의 list?
	int count;
};

// 새로운 list 생성을 도와줄 함수
struct list *createList(char *name, char *log){
	// 새로운 list
	struct list *newList;
	newList = (struct list*)malloc(sizeof(struct list));
	
	strcpy(newList->name, name);
	strcpy(newList->log, log);
	newList->next = NULL;
	
	return newList;
};

void insert(char *name, char *log);
void remove_name(char *name);
void display();
void merge(char (*login)[6], int left, int mid, int right);
void merge_sort(char (*login)[6], int left, int right);

int main(void){
	
	/*
	해결해야 하는 조건
	
	list = 2 <= n <= 10^6 100만
	
	enter - 출근
	leave - 퇴근
	
	출근한 직원은 누구?
	strcmp(enter, ?)
	
	사전순의 역순
	*/
	
	int n;
	
	// 기록의 수 n
	scanf("%d", &n);
	
	struct list list[n];
	hashTable = (struct bucket*) malloc(SIZE*sizeof(struct bucket));
	for (int i = 0; i < n; i++){
		scanf("%s %s", list[i].name, list[i].log);
		insert(list[i].name, list[i].log);
		if (strcmp(list[i].log, (char*)"leave")==0){
			remove_name(list[i].name);
		}
	}
	display();
	
	merge_sort(login, 0, c-1);
	
	for (int i = 0; i < c; i++){
		printf("%s\n", login[i]);
	}
	
	return 0;
}
	
// hash function
unsigned long strFunction(const char *name){
	// 해시 충돌(hash collision) 방지
    unsigned long strFunction = 7919; // 소숫 값
    int a;
	// 문자
    while (a = *name++) {
        strFunction = (((strFunction<<4)+strFunction)+a)%SIZE;
    }
    return strFunction%SIZE;
}
// hash map에 list를 넣는 함수
void insert(char *name, char *log){
	// 어느 bucket?
	int hashIndex = strFunction(name);	
	struct list *newList = createList(name, log);
	// 인덱스에 없는 경우
	if (hashTable[hashIndex].count == 0){
		hashTable[hashIndex].head  = newList;
		hashTable[hashIndex].count = 1;
	}
	// 있는 경우
	else{
		newList->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newList;
		hashTable[hashIndex].count++;
	}
	
	return;
}
// hash map에 있는 함수를 지우는 함수
void remove_name(char *name){
	// 지우고자 하는 name이 어느 bucket?
	int hashIndex = strFunction(name);
	
	struct list *list;
	struct list *temp;
	list = hashTable[hashIndex].head;
	
	// 지우고자 하는 bucket에 아무것도 없는 경우
	if (list == NULL){
		return;
	}
	// 있는 경우
	while (list != NULL){
		do {
			// list에 name이 있는 경우
			if (strcmp(list->name, name) == 0){
				// head라면 지우고 한 칸 옆으로 이동
				if (list == hashTable[hashIndex].head){
					hashTable[hashIndex].head = list->next;
				}
				// 아니라면 다음 값을 현재 list의 다음 값으로
				else{
					temp->next = list->next;
				}
				// list의 값을 지워 주었기 때문에 count-1
				hashTable[hashIndex].count--;
				// list 값 지우기
				free(list);
			}
		} while(0);
		// next list로 되기 전에 list값 저장
		temp = list;
		list = list->next;
	}
	return;
}
// login 직원
void display(){
	
	// hashTable 전체의 bucket안의 list를 확인
	struct list *enter;
	
	// loop를 돌려야 하기 때문
	int i = 0;
	
	// 모든 bucket을 확인할 for문
	for (i = 0; i < SIZE; i++){
		
		// hashTable 0 ~ 9까지 확인 bucket의 head부터 시작
		enter = hashTable[i].head;
		
		// NULL인지 확인
		while (enter != NULL){
			if (strcmp(enter->log, (char*)"enter")==0){
				strcpy(login[c++], enter->name);
			}
			enter = enter->next;
		}
	}
	return;	
}
// 사전 순의 역순
void merge(char (*login)[6], int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;

	while(l <= mid && m <= right){
		
		if (strcmp(login[l], login[m])>0){
			strcpy(sorted[k], login[l]);
			k++, l++;
		}
		
		else{
			strcpy(sorted[k], login[m]);
			k++; m++;
		}
	}
	
	if (l > mid){
		for (int i = m; i <= right; i++){
			strcpy(sorted[k], login[i]);
			k++;
		}
	}
	else {
		for (int j = l; j < m; j++){
			strcpy(sorted[k], login[j]);
			k++;
		}
	}
	
	for (int i = left; i <= right; i++){
		strcpy(login[i], sorted[i]);
	}
}
void merge_sort(char (*login)[6], int left, int right){
	
	int mid = (left+right)/2;
	
	if (left < right){
		merge_sort(login, left, mid);
		merge_sort(login, mid+1, right);
		merge(login, left, mid, right);
	}
}