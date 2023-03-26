#include <stdio.h>

int main(void)
{
	//배열
	// int subway_array[3]; // [숫자] 여러 개의 변수를 함께, 동시에 생성 [0][1][2]
	// subway_array[0] = 30;
	// subway_array[1] = 40;
	// subway_array[2] = 50;
	
	// for (int i = 0; i < 3; i++)
	// {
	// 	printf("지하철 %d호차에 %d 명이 타고 있습니다.\n", i + 1, subway_array[i]);
	// }
	
	// 값 설정 방법
	// 값은 반드시 초기화를 해야한다.
	// int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // {초기화 값} 값을 초기화를 하지 않으면 더미값 즉, 필요없는 값이 나온다. 
	// for (int i = 0; i < 10; i++)
	// {
	// 	printf("\n%d", arr[i]);
	// }
	
	// 배열 크기는 항상 상수로 선언
	// int size = 10;
	// int arr[10];
	
	// int arr[10] = {1, 2}; // 3번째 값부터는 자동으로 '0'으로 초기화 됨 
	// for (int i = 0; i < 10; i++)
	// {
	// 	printf("\n%d", arr[i]);
	// }
	
	// int arr[] = {1, 2}; // arr[2]의 값과 동일하다.
	
	// float arr_f[5] = {1.0f, 2.0f, 3.0f};
	// for (int i = 0; i < 5; i++)
	// {
	// 	printf("%.2f\n", arr_f[i]);
	// }
	
	// 문자 vs 문자열
	// char c = 'A';
	// printf("%c\n", c);
	
	// 문자열 끝에는 문자의 끝을 의미하는 NULL 문자 '\0' 아 포함되어야 한다.
	// char str[6] = "coding"; // [c][o][d][i][n][g][\0]
	// char str[7] = "coding"; // 문자열 남은 한 칸에 자동으로 [\0]이 들어감.
	// printf("%s\n", str);
	
	// char str[] = "coding";
	// // printf("%s\n", str);
	// // printf("%ld\n", sizeof(str));
	
	// for (int i = 0; i < sizeof(str); i++)
	// {
	// 	printf("%c\n", str[i]);	
	// }	

	// 	char kor[] = "pulljump";
	// 	printf("%s\n", kor);
	// 	printf("%ld\n", sizeof(kor));

	// char c_array[7] = {'c', 'o', 'd', 'i', 'n', 'g', '\0'};
	// char c_array[6] = {'c', 'o', 'd', 'i', 'n', 'g'};
	// printf("%s\n", c_array);
	
	char c_array[10] = {'c', 'o', 'd', 'i', 'n', 'g'};
	printf("%s\n", c_array);
	for (int i = 0; i < sizeof(c_array); i++)
	{
		printf("%d\n", c_array[i]); // ASCII 코드 값 출력(NULL문자는 0으로 출력)
	}	
	// ASCII 코드란 ANSI (미국표준협회) 에서 제시한 표준 코드 체계.
	
	return 0;
}