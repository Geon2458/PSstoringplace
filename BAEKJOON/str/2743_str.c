#include <stdio.h>
#include <string.h>

int main(void)
{ 
	char arr[101] = {0};
	
	scanf("%s", arr);
	
 	printf("%ld", strlen(arr));	// 문자길이(string lenght) 에서 따옴 string.h 헤더 파일에 저장 되어 있음.
	
	return 0;
}