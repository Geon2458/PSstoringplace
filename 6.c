#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomnumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
	// 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 랜덤
	srand(time(NULL));
	int count = 0;
	for(int i = 1; i <= 5; i++)
	{
		// x * y = ?
		int num1 = getRandomnumber(i); // (i) 더 어려운 수식을 만들기 위해 i를 활용하여 더 큰 숫자를 넣어지게 만든다. 
		int num2 = getRandomnumber(i);
		//printf("%d x %d ?", num1, num2);
		showQuestion(i, num1, num2);
		
		int answer = -1;
		scanf("%d", &answer);
		if (answer == -1)
		{
			printf("프로그램을 종료합니다.\n");
			exit(0);
		}
		else if (answer == num1 * num2)
		{
			success();
			count++; // 총 맞힌 문제의 개수를 정의
		}
		else
		{
			fail();
		}
		
	}
	
	printf("\n\n 당신은 5개의 도어락 비밀번호 중 %d개를 맞혔습니다.\n", count);
	
	return 0;
}

int getRandomnumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n########## %d 번째 비밀번호 ##########\n", level);
	printf("\n\t     %d x %d = ?\n\n", num1, num2);
	printf("#####################################\n\n");
	printf("\n비밀번호를 입력하세요 (종료 : -1) >> ");
}

void success()
{
	printf("\n >> GOOD! 정답입니다.\n");
}
void fail()
{
	printf("\n >> 땡 ! 틀렸습니다.\n");
}