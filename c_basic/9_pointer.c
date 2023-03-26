#include <stdio.h>

int main(void)
{
	// 포인터
	// [철수]
	// [영희]
	// [민수]
	int A = 1;
	int B = 2;
	int C = 3;
	
	printf("철수네 주소 : %ld, 암호 : %d\n", &A, A);
	printf("영희네 주소 : %ld, 암호 : %d\n", &B, B);
	printf("민수네 주소 : %ld, 암호 : %d\n", &C, C);
	
	// 미션맨
	int * M;
	M = &A;
	printf("미션맨이 방문한 곳 주소 : %ld, 암호 : %d\n", M, *M);
	
	M = &B;
	printf("미션맨이 방문한 곳 주소 : %ld, 암호 : %d\n", M, *M);
	
	M = &C;
	printf("미션맨이 방문한 곳 주소 : %ld, 암호 : %d\n", M, *M);
	
	M = &A;
	*M = *M * 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %ld, 암호 : %d\n", M, *M);
	
	M = &B;
	*M = *M * 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %ld, 암호 : %d\n", M, *M);
	
	M = &C;
	*M = *M * 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %ld, 암호 : %d\n", M, *M);
	
	// 스파이
	int * S = M;
	printf("\n ... 스파이가 미션 수행하는 중 ... \n\n");
	S = &A;
	*S = *S - 2;
	printf("스파이가 방문하는 곳 주소 : %ld, 암호 : %d\n", S, *S);
	
	S = &B;
	*S = *S - 2;
	printf("스파이가 방문하는 곳 주소 : %ld, 암호 : %d\n", S, *S);
	
	S = &C;
	*S = *S - 2;
	printf("스파이가 방문하는 곳 주소 : %ld, 암호 : %d\n", S, *S);
	
	printf("\n ... 영희 민수는 집에 오고서는 바뀐 비밀번호를 보고 깜놀 ... \n\n");
	
	printf("철수네 주소 : %ld, 암호 : %d\n", &A, A);
	printf("영희네 주소 : %ld, 암호 : %d\n", &B, B);
	printf("민수네 주소 : %ld, 암호 : %d\n", &C, C);
	
	printf("미션맨네 주소 : %ld\n", &M);
	printf("스파이네 주소 : %ld\n", &S);
	
	return 0;
}