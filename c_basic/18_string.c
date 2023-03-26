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
	*/	
	// QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.
		
		
	// char arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	return 0;
}