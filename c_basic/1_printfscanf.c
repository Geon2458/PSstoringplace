#include <stdio.h>

int main(void)
{
	// Project. 경찰서 조사 쓰기.
	// 이름? 나이? 몸무게? 키? 범죄내용?
	char name[256];
	printf("이름이 뭐에요? ");
	scanf("%s", name);
	
	int age;
	printf("나이가 어떻게 되세요? ");
	scanf("%d", &age);
	
	float weight;
	printf("몸무게가 몇 kg이세요? ");
	scanf("%f", &weight);
	
	double height;
	printf("키가 몇 cm세요? ");
	scanf("%lf", &height);
	
	char what[256];
	printf("무슨 죄를 저질렀어요? ");
	scanf("%s", what);
	
	
	printf("\n\n########---범죄 내용---########\n\n");
	printf(" 이름              : %s\n", name);
	printf(" 나이              : %d\n", age);
	printf(" 몸무게            : %.2f\n", weight);
	printf(" 키                : %.2lf\n", height);
	printf(" 범죄 내용         : %s\n", what);
	
	
	return 0;
}