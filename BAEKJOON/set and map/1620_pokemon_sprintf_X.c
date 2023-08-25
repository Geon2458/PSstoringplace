#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bucket *hashTable = NULL;

struct Pokemon{
	char name[25];
	int  num;
	
	char question[25];
	
	struct Pokemon *next;
};

struct bucket{
	
	struct Pokemon *head;
};

struct Pokemon *createList(char *name, int num){
	
	struct Pokemon *newList;
	
	// newList의 메모리 할당
	newList = (struct Pokemon*)malloc(sizeof(struct Pokemon));
	
	strcpy(newList->name, name);
	newList->num  = num;
	newList->next = NULL;
	
	return newList;
};

void insert(char *name, int num);
void search(char *name);

int main(void){
	
	/*
	해결해야 하는 조건
	
	question
	문자 -> 숫자 출력
	숫자 -> 문자 출력
	
	n, m 10만
	
	hash map?
	cmp비교?
	*/
	
	int n, m;
	
	scanf("%d %d", &n, &m);

	struct Pokemon *list = (struct Pokemon*)malloc(sizeof(struct Pokemon)*n);
	hashTable = (struct bucket*)malloc(2*sizeof(struct bucket)*n);
	
	for (int i = 1; i <= n; i++){
		scanf("%s", list[i].name);
		list[i].num = i;
		insert(list[i].name, list[i].num);
	}
	
	struct Pokemon *Q = (struct Pokemon*)malloc(sizeof(struct Pokemon)*m);
	for (int i = 1; i <= m; i++){
		scanf("%s", Q[i].question);
	}
	
	for (int i = 1; i <= m; i++){
		if (atoi(Q[i].question)>0){
			printf("%s\n", list[atoi(Q[i].question)].name);
		}
		else{
			search(Q[i].question);
		}
	}
	
	free(list);
	free(Q);
	
	return 0;
}

unsigned long long hashFunction(char *name){
	
	unsigned long long hashFunction = 5381;
	unsigned long long a;
	while (a = *name++){
		hashFunction = (((hashFunction<<7)+hashFunction)+a)%5381;
	}
	
	return hashFunction%5381;
}

void insert(char *name, int num){
	
	int hashIndex = hashFunction(name);
	
	struct Pokemon *newPokemon = createList(name, num);
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
	
	return;
}

void search(char *name){
	
	int hashIndex = hashFunction(name);
	struct Pokemon *pokemon = hashTable[hashIndex].head;

	while (pokemon != NULL){
		if (strcmp(pokemon->name, name)==0){
			printf("%d\n", pokemon->num);
			break;
		}
		pokemon = pokemon->next;
	}
	
	return;
}