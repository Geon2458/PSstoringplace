#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	//Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1부터 100 사이의 숫자
	printf("숫자 : %d\n\n\n\n\n\n\n\n\n\n\n\n", num);
	int answer = 0; // 정답
	int chance = 5; // 기회
	while (chance > 0)
	{
		printf("남은 기회 %d번 \n", chance--);
		printf("숫자를 맞혀보새요 (1 ~ 100) : ");
		scanf("%d", &answer);
		
		if (answer > num)
		{
			printf("\nDOWN ↓\n\n");
		}
		else if (answer < num)
		{
			printf("\nUP ↑\n\n");
		}
		else if (answer == num)
		{
			printf("\n\n정답입니다 !\n\n");
			break;
		}
		else
		{
			printf("\n\n알 수 없는 오류가 발생하였습니다.\n\n");
		}
		if (chance == 0)
		{
			printf("\n\n모든 기회를 다 사용하셨습니다. 실패하였습니다.\n\n");
			break;
		}
	}
	
	return 0;
}