#include <stdio.h>
#include <string.h>
char word_sorted[40001][51];

void merge_sort(char (*word)[51], int left, int right);
void merge(char (*word)[51], int left, int mid, int right);
int compare_word(char* a, char* b);

int main(void){
	
	/*
	해결해야 하는 조건
	
	n개의 단어 <= 20,000
	
	1. 길이 순 - strlen - strcpy
	2. 사전 순 - a ~ z = 97 ~ 122
	3. 중복 단어는 1개만 - strcmp
	
	strcpy - str (=string), cpy (=copy) 문자열을 복사하는 함수
	strcpy(a, b) -> b에 저장되어 있는 문자열 전체를 a로 카피
	
	strcmp - stt (=string), cmp (=compare) 문자열이 동일한지 비교하는 함수
	strcmp(a, b) -> 같으면 0 반환 다르면 0 이 아닌 값 반환
	
	0 : 정상 종료
	-1 : 에러 발생
	1이상 숫자 : 정상 종료 되었으나 다른 무엇인가 있음을 나타냄
	-2 같은 숫자 : 에러 발생했으나 구체적으로 무엇이다를 나타냄

	0과 -1의 경우 위의경우처럼 해석하고
	1이상, -2 이상의 숫자의 경우는
	구체적으로 무엇때문이다라는 것을 외부에 알려줄때 사용
	*/
	
	int n;
	char word[20001][51];
	
	// n개의 단어
	scanf("%d", &n);
	
	// 단어를 char배열에 저장
	for (int i = 0; i < n; i++){
		scanf("%s", word[i]);
	}
	
	merge_sort(word, 0, n-1);
	
	for (int i = 0; i < n; i++){
		if (strcmp(word[i], word[i+1]) == 0){
			continue;
		}
		printf("%s\n", word[i]);
	}
	return 0;
}

// 오류가 있을 시 return -1
// strlen(word[l]) > strlen(word[m]) or == && strcmp(word[l], word[m]) > 0 return 1
// else return 0
int compare_word(char *a, char *b){
	int s1 = strlen(a);
	int s2 = strlen(b);
	if (s1 > s2 || s1 == s2 && strcmp(a, b) > 0) return -1;
	return 0;
}

// 글자수 사전순으로 정렬
void merge(char (*word)[51], int left, int mid, int right){
	int l = left;
	int m = mid+1;
	int k = left;

	while(l <= mid && m <= right){
		
		if (compare_word(word[l], word[m])){
			strcpy(word_sorted[k], word[m]);
			k++; m++;
		}
		
		else{
			strcpy(word_sorted[k], word[l]);
			k++, l++;
		}
	}
	
	if (l > mid){
		for (int i = m; i <= right; i++){
			strcpy(word_sorted[k], word[i]);
			k++;
		}
	}
	else {
		for (int j = l; j < m; j++){
			strcpy(word_sorted[k], word[j]);
			k++;
		}
	}
	
	for (int i = left; i <= right; i++){
		strcpy(word[i], word_sorted[i]);
	}
}

void merge_sort(char (*word)[51], int left, int right){
	
	int mid = (left+right)/2;
	
	if (left < right){
		merge_sort(word, left, mid);
		merge_sort(word, mid+1, right);
		merge(word, left, mid, right);
	}
}