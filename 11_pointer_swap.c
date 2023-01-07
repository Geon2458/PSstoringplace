#include <stdio.h>

void swap(int a, int b);
void swap_addr(int * a, int * b);
void changeArray(int * ptr);

int main(void)
{
	// int a = 10;
	// int b = 20;
	// printf("a 의 주소 : %ld\n", &a);
	// printf("b 의 주소 : %ld\n", &b);
	// // a와 b의 값을 바꾼다.(Swap)
	// printf("Swap 함수 전 => a : %d, b : %d\n", a, b);
	// swap(a, b);
	// printf("Swap 함수 후 => a : %d, b : %d\n", a, b);
	
	// // 값에 의한 복사 (Call by value) -> 값만 복사한다는 의미
	
	// // 주소값을 넘기면? 메모리 공간에 있는 주소값 자체를 넘기면... 
	// printf("(주소값 전달)Swap 함수 전 => a : %d, b : %d\n", a, b);
	// swap_addr(&a, &b);
	// printf("(주소값 전달)Swap 함수 후 => a : %d, b : %d\n", a, b);
	
	// 배열일 때, arr2 -> 주소
	int arr2[3] = {10, 20, 30};
	// changeArray(arr2);
	changeArray(&arr2[0]);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}
	
	// scanf 에서 &num 과 같이 & 를 사용하는 이유?
	
	return 0;
}

void swap(int a, int b)
{
	printf("(Swap 함수 내)a 의 주소 : %ld\n", &a);
	printf("(Swap 함수 내)b 의 주소 : %ld\n", &b);
	
	int temp = a;
	a = b;
	b = temp;
	printf("Swap 함수 내 => a : %d, b : %d\n", a, b);
}

void swap_addr(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(주소값 전달)Swap 함수 내 => a : %d, b : %d\n", *a, *b);
}

void changeArray(int * ptr)
{
	ptr[2] = 50;
}