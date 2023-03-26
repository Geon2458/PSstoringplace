#include <stdio.h>

#difine MAX 100000 // 상수가 되고, MAX는 무조건 10,000으로 치환

int main(void)
{
	// 파일 입출력
	// 파일에 어떤 데이터를 저장
	// 파일에 저장된 데이터 불러오기
	
	// fputs, fgets 쌍
	char line[MAX]; // char line[10000] 과 똑같다.
	FILE * file = fopen("c:\\test1.txt", "wb"); // 파일을 여는 방식 r(read) w(write) a(append), 뒤에 붙는 것 t(text) b(binary data, 이진 데이터)
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	
	while (fget (line, MAX, file) != N )
	
	fputs("fputs 를 이용해서 글을 적어볼게요.\n", file);
	fputs("잘 적히는지 확인해 주세요.\n", file);
	
	// 파일을 열고 나서 파일을 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면?
	// 데이터 손실이 발생 가능 ! 그래서 항상 파일은 닫아주는 습관을 들여주세요
	fclose(file); // file을 저장 후 닫음
	
	// fprintf, fscanf 쌍
	
	
	
	return 0;
}