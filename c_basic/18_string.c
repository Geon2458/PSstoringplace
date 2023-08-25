#include <stdio.h>

int main(void)
{
	char arr[4] = "ABC";
	char arr[] = "ABC";
	char arr[] = {'A', 'B', 'C', }
	
	// 띄어쓰기 적용하는 방법
	
	int a;
	char arr[1001];
	
	scanf("%[^\n]", arr);
	printf("%s", arr, sizeof(arr));
	
	char str[101];
	
	while ((str[101] = getchar()) != EOF)
	{
		putchar(str[101]);
	}
	
	/*
	atoi(문자열);
	int atoi(char const *_String);
	성공하면 변환된 정수를 반환, 실패하면 0을 반환
	
	먼저 문자열을 정수로 바꾸는 방법
	atoi 함수를 사용하면 10진법으로 표기된 문자열을 정수로 바꿀 수 있으며
	함수 이름은 ASCII string to integer에서 따옴(stdlib.h 헤더 파일에 선언되어 있음)
	
	********************************
	* 1. %d : 10진수로 출력 정수형     *
	* 2. %f : 실수형                 *
	* 3. %e : 지수형                 *
	* 4. %o : 8진수로 출력            *
	* 5. %x : 16진수로 출력           *
	* 6. %u : 부호없는 10진수로 출력    *
	* 7. %g : 실수형으로 자동 출력      *
	* 8. %p : 포인터의 주소를 출력      *
	* 9. %c : 하나의 문자로 출력 문자형  *
	* 10. %s : 문자열을 출력           *
	*********************************
	// QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.
	
	a ~ z = 97 ~ 122
	
	A ~ Z = 65 ~ 90
	
	0 ~ 9 = 48 ~ 57
	
	// char arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	char abc[] = {'A', 'B', 'C'};
	char def[] = {'D', 'E', 'F'};
	char ghi[] = {'G', 'H', 'I'};
	char jkl[] = {'J', 'K', 'L'};
	char mno[] = {'M', 'N', 'O'};
	char pqrs[] = {'P', 'Q', 'R', 'S'};
	char tuv[] = {'T', 'U', 'V'};
	char wxyz[] = {'W', 'X', 'Y', 'Z'};
	
	먼저 문자열의 맨 마지막에 '\0'이 들어갈 것을 고려해서 
	s의 크기를 최소한 1,000,001 이상으로 잡아줘야 합니다.

	그리고 8번 줄에서 for문의 조건으로 strlen을 사용했는데 
	이렇게 하면 매번 loop할 때 마다 문자열의 길이를 다시 계산하므로 성능에 악영향을 끼칠 수 있습니다.

	다른 변수에 문자열 s의 길이를 저장해놓고 사용하는 것을 추천합니다.

	마지막으로 9번 줄의 for문은 단순히 s[i]의 값을 보고 
	for문 없이 바로 count 배열의 값을 증가시키도록 바꿀 수 있습니다.
	
	문자형	
	(signed) char                   1 byte (8 bit)       -128 ~ 127
	unsigned char	                1 byte (8 bit)       0 ~ 255
	
	정수형	
	(signed) short (int)            2 byte (16 bit)      -32,768 ~ 32,767
	unsigned short (int)	        2 byte (16 bit)      0 ~ 65,535
	(signed) int	                4 byte (32 bit)      -2,147,483,648 ~ 2,147,483,647
	unsigned int	                4 byte (32 bit)      0 ~ 4,294,967,295
	(signed) long (int)	            8 byte (64 bit)      -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
	unsigned long (int)	            8 byte (64 bit)      0 ~ 18,446,744,073,709,551,615
	(signed) long long (int)	    8 byte (64 bit)      -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
	unsigned long long (int)	    8 byte (64 bit)      0 ~ 18,446,744,073,709,551,615
	
	실수형	
	float                           4byte (32bit)        ±3.4×10^(-37) ~ ±3.4×10^(38)
	double	                        8byte (64bit)        ±1.7×10^(-307) ~ ±1.7×10^(308)
	long double	                    8byte (64bit)        ±1.7×10^(-307) ~ ±1.7×10^(308) 이상
	
                                                                               -https://sweetnew.tistory.com/16-
	
	*/
	
	return 0;
}