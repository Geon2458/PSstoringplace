#include <stdio.h>
#include <stdlib.h>

// 해시(hash)란 다양한 길이를 가진 데이터를 고정된 길이를 가진 데이터로 매핑(mapping)한 값

// 모든 bucket에 접근할 수 있는 hashTable
struct bucket *hashTable = NULL;

// hash맵에 몇개의 bucket을 갖고 시작할지
int SIZE = 10;

struct node{
	
	int key;
	int value;
	
	// 체이닝할 때 다음 노드를 알려줄 nextNode
	struct node *next;
};

struct bucket{
	
	// 제일 처음 Node를 가리키는 headNode
	struct node *head;
	
	// bucket안에 몇개의 node를 갖고 있는지 알려줄 count
	int count;
};

// 넣고 뺄때 노드를 생성해서 insert를 해야하야기 때문에
// 그 생성을 도와줄 createNode
struct node *createNode(int key, int value){
	
	// 새로운 노드
	struct node *newNode;
	
	// newNode의 메모리 할당
	newNode = (struct node *)malloc(sizeof(struct node));
	
	// key와 value와 *next를 기본값으로 세팅(초기 값으로 새로운 노드 값 초기화)
	// 유저가 만들고자하는 key 값
	newNode->key = key;
	
	// 유저가 넣고 싶은 value
	newNode->value = value;
	
	// NULL로 초기화
	newNode->next = NULL;
	
	// 할당 받은 node를 return
	return newNode;
};

int hashFunction(int key){
	
	// if key=1 1%10 = 1 1번 버켓 next key=21 21%10 = 1 1번 버켓
	return key%SIZE;
}

// 해시 함수의 간단한 해싱 방법
// hash map에 node를 넣는 insert(유저가 넣고자 하는 key와 value를 받음(createNode))
void insert(int key, int value){
	
	// 어디 bucket에 들어가는지
	int hashIndex = hashFunction(key);
	
	struct node *newNode = createNode(key, value);
	
	// 내가 넣고자 하는 인덱스에 값이 없는 경우
	if (hashTable[hashIndex].count == 0){
		
		hashTable[hashIndex].head  = newNode;
		hashTable[hashIndex].count = 1;
	}
	
	// 내가 넣고자 하는 인덱스에 이미 값이 있는 경우
	else{
		
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
	}
	
	return;
}

// hash map에 있는 원하는 함수를 지우는 일
void remove1(int key){
	
	// 지우고자 하는 key가 어느 bucket에 있는지(hash 값 받아오기)
	int hashIndex = hashFunction(key);
	
	// 체이닝 되어 있는지 확인
	struct node *node;
	// node 뒤에 어떤 node가 있는 확인을 위해(중간에 있는 노드를 없애는 경우 이전 노드 추척)
	struct node *trace;
	
	// 해당 bucket의 head를 *(포인트)
	node = hashTable[hashIndex].head;
	
	// 지우고자 하는 bucket에 아무것도 없는 경우
	if(node == NULL){
		printf("\nno key found!");
		return;
	}
	
	// 있는 경우
	while(node != NULL){
		
		// node에 key가 있는 경우
		if (node->key == key){
			
			// node가 hashTable의 head일 경우(next 포인터를 바꾸어 주는 부분)
			if(node == hashTable[hashIndex].head){
				
				// head라면 한 칸 옆으로 이동하라
				hashTable[hashIndex].head = node->next;
			}
			
			// 아닐 경우
			else{
				
				// trace 다음 값을 현재 노드의 다음 값을 포인트 하게 해준다
				// 1 2 3 -> (1 = trace / 2 = node / 3 = node next) -> 1 3
				trace->next = node->next;
			}
			
			// 3개의 값에서 2번째 node값을 지워 주었으므로 2개의 값이기 때문에 count-1
			hashTable[hashIndex].count--;
			// node 값 지우기
			free(node);
			return;
		}
		// node next가 되기 전에 node 값 받기
		trace = node;
		node  = node->next;
	}
	
	// 없는 경우
	printf("\nno key found!");
	return;
}

// 원하는 node가 있는지 없는지 알려줄 search
void search(int key){
	
	// 해당 key가 어느 bucket에 있는지
	int hashIndex = hashFunction(key);
	
	// head를 비교할 node
	struct node *node = hashTable[hashIndex].head;
	
	// bucket에 없는 경우
	if (node == NULL){
		printf("\nno key found!");
		return;
	}
	
	// 있는 경우
	while (node != NULL){
		
		// 현재 node에 찾던 key를 찾았을 경우
		if (node->key == key){
			printf("\nkey found key = [%d] value = [%d]", node->key, node->value);
			return;
		}
		
		// 다음 node로 계속 이동하며 탐색
		node = node->next;
	}
	
	printf("\nno key found!");
	return;
}

// hashTable 전체의 현재 상황을 print 해줄 수 있는 display(중요도 x)
void display(){
	
	// hashTable 전체의 bucket안의 node를 확인
	struct node *horse;
	
	// loop를 돌려야 하기 때문
	int i = 0;
	
	// 모든 bucket을 확인할 for문
	for (i = 0; i < SIZE; i++){
		
		// hashTable 0 ~ 9까지 확인 bucket의 head부터 시작
		horse = hashTable[i].head;
		
		// 몇 번째 head에 있는가
		printf("Bucket[%d] : ", i);
		
		// NULL인지 확인
		while (horse != NULL){
			printf("(key:%d, val:%d) -> ", horse->key, horse->value);
			horse = horse->next;
		}
		
		// 하나의 bucket을 다 돌고 난 후 다음 라인으로
		printf("\n");
	}
	printf("\n---------end of display---------\n");
	return;
}

int main(void){
	
	// hashTable 초기화 / 메모리 size = bucket*size
	hashTable = (struct bucket*) malloc(SIZE*sizeof(struct bucket));
	
	insert(0,   1);
	insert(1,  10);
	insert(11, 90);
	insert(11, 64);
	insert(31, 23);
	insert(6,  25);
	insert(97,  4);
	
	display();
	
	// 지울 head
	int m;
	scanf("%d", &m);
	remove1(m);
	remove1(11);
	
	// 검색
	search(6);
	search(85);
	
	display();
	
	return 0;
}

//https://kirkim.github.io/c/2021/04/22/hash4.html