#include <stdio.h>

// malloc 함수가 포함된 헤더 파일
#include <stdlib.h>

void main(){
	
	/*
	arr   <- (int*) 대입
	malloc(sizeof(int)*x) xbyte 할당 -> 힙 영역에서 생성
	void* -> (int*)
	
	malloc은 return 값으로 void형 pointer를 리턴
	
	인자 값으로 sizeof(int)를 하는 이유는 int의 크기만큼을 할당 받아야하기 때문에
	int의 크기와 할당 받을 크기를 서로 '곱해주어' 최종 메모리의 크기를 넣어 준다
	
	free(메모리 해제)
	프로그램이 종료될 때까지 메모리 사용량이 계속 증가 -> 메모리 누수 현상
	malloc 함수 사용시 꼭 free함수를 사용하여 회수해야한다
	*/
	int *arr;
	
	// size 4 동적할당(프로그램 실행 도중에 사용할 메모리 공간을 할당한다)
	arr = (int*)malloc(sizeof(int)*4);
	
	arr[0] = 100;
	arr[1] = 200;
	arr[2] = 300;
	arr[3] = 400;
	
	for (int i = 0; i < 4; i++){
		printf("arr[%d] : %d\n", i, arr[i]);
	}
	
	// 동적할당 해제
	free(arr);
	
}