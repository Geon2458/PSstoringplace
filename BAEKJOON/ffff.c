#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bucket *hashTable = NULL;

char sorted[200001][51];
	
struct pokemon{
	
	char name[21];
	char num[100001];
	
	// 다음 포켓몬
	struct pokemon *next;
};

struct bucket{
	
	struct pokemon *head;
};

struct pokemon *createList(char *name, char *num){
	// insert에 들어갈 포켓몬
	struct pokemon *newPokemon;
	newPokemon = (struct pokemon*)malloc(sizeof(struct pokemon));
	
	strcpy(newPokemon->name, name);
	strcpy(newPokemon->num, num);
	newPokemon->next = NULL;
	
	return newPokemon;
};

void insert(char *name, char *num);
void Namesearch(char *name);
void Numsearch(char *num);
void merge(struct pokemon *list, int left, int mid, int right);
void merge_sort(struct pokemon *list, int left, int right);
int binsreach_Name(struct pokemon *list, int n, char *q);
int binsreach_Num(struct pokemon *list, int n, char *q);

int main(void){
	
	/*
	해결해야 하는 조건
	
	포켓몬 수 N <= 10만
	문제의 수 M <= 10만
	
	이름 길이 <= 20
	
	문제 이름 -> 숫자
	    숫자 -> 이름
	*/
	
	int n, m;
	scanf("%d %d", &n, &m);
	char question[m][21];
	
	struct pokemon list[n];
	hashTable = (struct bucket*)malloc(sizeof(struct bucket));
	
	for (int i = 1; i <= n; i++){
		scanf("%s", list[i].name);
		// 숫자를 문자열로 저장
		sprintf(list[i].num, "%d", i);
		insert(list[i].name, list[i].num);
	}
	
	for (int j = 1; j <= m; j++){
		scanf("%s", question[j]);
	}
	
	merge_sort(list, 1, n);

	for (int i = 1; i <= m; i++){
		if (atoi(question[i])>0){
			binsreach_Num (list, n, question[i]);
		}
		else{
			 binsreach_Name(list, n, question[i]);
		}
	}
	
	return 0;
}

int binsreach_Name(struct pokemon *list, int n, char *q){
	int low = 1;
	int high = n;
	
	while (low<=high){
		int mid = (low+high)/2;
		
		if (strcmp(q, list[mid].name)==0){
			Namesearch(list[mid].name);
			break;
		}
		else if (strcmp(q, list[mid].name) < 0){
			high = mid -1;
		}
		else if (strcmp(q, list[mid].name) > 0){
			low = mid +1;
		}
	}
}

int binsreach_Num(struct pokemon *list, int n, char *q){
	int low = 1;
	int high = n;
	
	while (low<=high){
		int mid = (low+high)/2;
		// 숫자로 바꾸어 비교
		if (atoi(list[mid].num) == atoi(q)){
			Numsearch(list[mid].num);
			break;
		}
		else if (atoi(list[mid].num) > atoi(q)){
			high = mid -1;
		}
		else if (atoi(list[mid].num) < atoi(q)){
			low = mid +1;
		}
	}
}

void merge(struct pokemon *list, int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;
	
	while (l<=mid && m<=right){
		if (strcmp(list[l].name, list[m].name)>0){
			strcpy(sorted[k++], list[m++].name);
		}
		else{
			strcpy(sorted[k++], list[l++].name);
		}
	}
	
	while(l<=mid){
		strcpy(sorted[k++], list[l++].name);
	}
	while(m<=right){
		strcpy(sorted[k++], list[m++].name);
	}
	
	for (int i = left; i <= right; i++){
		strcpy(list[i].name, sorted[i]);
	}
}

void merge_sort(struct pokemon *list, int left, int right){
	int mid = (left+right)/2;
	
	if (left<right){
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}

int hashFunction(const char *name){
	
	int hashFunction = 103;
	int a;
	while (a = *name++){
		hashFunction = (hashFunction+a)%103;
	}
	return hashFunction%103;
}

int NumFunction(const char *num){
	
	int NumFunction = 103;
	int a;
	while (a = *num++){
		NumFunction = (NumFunction+a)%103;
	}
	return NumFunction%103;
}

void insert(char *name, char *num){
	
	int hashIndex = hashFunction(name);
	int numIndex  = NumFunction(num);
	struct pokemon *newPokemon = createList(name, num);
	// Index에 없는 경우
	if (hashTable[hashIndex].head == NULL){
		hashTable[hashIndex].head  = newPokemon;
	}
	// Index에 있는 경우
	else{
		// next로 넘긴 후
		newPokemon->next = hashTable[hashIndex].head;
		// 해당 자리에 newPokemon 저장
		hashTable[hashIndex].head = newPokemon;
	}
	if (hashTable[numIndex].head == NULL){
		hashTable[numIndex].head  = newPokemon;
	}
	// Index에 있는 경우
	else{
		// next로 넘긴 후
		newPokemon->next = hashTable[numIndex].head;
		// 해당 자리에 newPokemon 저장
		hashTable[numIndex].head = newPokemon;
	}
	
	return;
}

void Namesearch(char *name){
	
	int hashIndex = hashFunction(name);
	struct pokemon *pokemon = hashTable[hashIndex].head;
	
	// 없는 경우
	if (pokemon == NULL){
		return;
	}
	
	// 있는 경우
	while (pokemon != NULL){
		if (strcmp(pokemon->name, name)==0){
			printf("%s\n", pokemon->num);
			break;
		}
		pokemon = pokemon->next;
	}
	
	return;
}

void Numsearch(char *num){
	
	int hashIndex = NumFunction(num);
	struct pokemon *pokemon = hashTable[hashIndex].head;
	
	// 없는 경우
	if (pokemon == NULL){
		return;
	}
	
	// 있는 경우
	while (pokemon != NULL){
		if (strcmp(pokemon->num, num)==0){
			printf("%s\n", pokemon->name);
			break;
		}
		pokemon = pokemon->next;
	}
	
	return;
}