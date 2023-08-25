#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N, M;
char Dic[100005][24];

struct Mon{
	int num;
	char* name;
	struct Mon* next;
};

struct Bucket {
	struct Mon* mon;
};

struct Bucket* dict=NULL;

struct Mon* createMon(int num, char *name) {
	struct Mon* newnode;
	newnode = (struct Mon*)malloc(sizeof(struct Mon));
	newnode->num = num;
	newnode->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
	strcpy(newnode->name, name);
	newnode->next = NULL;
	return newnode;
}

int hash(char *name) {
	int result = 0;
	int len = strlen(name);
	for (int i = 0; i<len; i++) {
		result = (result*123+ name[i])%(2*N);
	}
	return result;
}

void insert(int num, char* name) {
	int idx = hash(name);
	struct Mon *new = createMon(num, name);
	if (dict[idx].mon == NULL) {
		dict[idx].mon = new;
	}
	else {
		new->next = dict[idx].mon;
		dict[idx].mon = new;
	}
	return;
}

int search(char *name) {
	int idx = hash(name);
	struct Mon* mon = dict[idx].mon;
	while (mon != NULL) {
		if (strcmp(mon->name, name) == 0) {
			return mon->num;
		}
		mon = mon->next;
	}
	return;
}

int main(void) {
	scanf("%d %d", &N, &M);
	char na[25], key;
	dict = (struct Bucket*)malloc(N * sizeof(struct Bucket)*2);
	memset(dict, 0, N * sizeof(struct Bucket) * 2);
	for (int i = 1; i <= N; i++) {
		scanf("%s", na);
		strcpy(Dic[i], na);
		insert(i, na);
	}
	int len;
	for (int i = 1; i <= M; i++) {
		scanf("%s", na);
		key = 0;
		len = strlen(na);
		if (na[0] < 65) {
			for (int j = 0; j < len ; j++) {
				key = key * 10 + na[j]-48;
			}
			printf("%s\n", Dic[key]);
		}
		else {
			printf("%d\n", search(na));
		}
	}
	return 0;
}