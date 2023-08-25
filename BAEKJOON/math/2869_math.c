#include <stdio.h>

int main(void){
	
	int a, b, v;     // 낮 a, 밤 b, 높이 v

	scanf("%d %d %d", &a, &b, &v);
	
	if ((v-b)%(a-b) != 0){
		printf("%d", (v-b)/(a-b)+1);            // v-b를 통해 낮에 길이를 넘어가는 것을 방지 만약 나머지가 0이 아닐 시 낮에 길이를 넘어가므로 +1일
	}
	else{
		printf("%d", (v-b)/(a-b));              // 나머지가 0일 시 길이와 낮에 올라간 길이가 맞아 떨어지기 때문에 +0일
	}
	
	return 0;
}