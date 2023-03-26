#include <stdio.h>

// struct = 구조체
struct GameInfo {
	char * name;
	int year;
	int price;
	char * company;
	
	struct GameInfo * friendGame; // 구조체 안에서 똑같은 구조체를 변수로 갖을 수 있다.
};

typedef struct GameInformation {
	char * name;
	int year;
	int price;
	char * company;
	
	struct GameInfo * friendGame; // 구조체 안에서 똑같은 구조체를 변수로 갖을 수 있다.
} GAME_INFO;

//  typedef struct { <- GameInformation를 사용하지 않아도 위와 똑같이 사용할 수 있음(단, typedef struct GameInformation 로 선언된 코드는 사용불가, GAME_INFO만 가능)
// 	char * name;
// 	int year;
// 	int price;
// 	char * company;
	
// 	struct GameInfo * friendGame; // 구조체 안에서 똑같은 구조체를 변수로 갖을 수 있다.
// } GAME_INFO;

int main(void)
{
	// [게임 출시]
	// 이름 : "랜덤 뽑기"
	// 2023.01.19
	// 가격 : 1000원
	// 제작사 : i회사
	
	char * name = "랜덤뽑기";
	int year = 2023;
	int price = 1000;
	char * company = "i회사";

	// [게임 출시]
	// 이름 : "랜덤 가차"
	// 2023.01.19
	// 가격 : 2,000원
	// 제작사 : j회사
	
	char * name2 = " 랜덤 가차";
	int year2 = 2023;
	int price2 = 2000;
	char * company2 = "j회사";
	
	// 구초체 사용
	struct GameInfo gameInfo1; // struct GameInfo <- GameInfo 까지 자료형 구조 gameInfo1;는 변수명
	gameInfo1.name = "랜덤뽑기";
	gameInfo1.year = 2023;
	gameInfo1.price = 1000;
	gameInfo1.company = "i회사";
	// struct GameInfo gameInfo2; 도 똑같이 사용 가능
	
	// 구조체 출력
	printf("-- i회사 게임 출시 정보 --\n");
	printf(" 게임명   : %s\n", gameInfo1.name);
	printf(" 발매년도 : %d\n", gameInfo1.year);
	printf(" 가격     : %d\n", gameInfo1.price);
	printf(" 제작사   : %s\n\n", gameInfo1.company);
	
	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = {"랜덤가차", 2023, 2000, "j회사"};
	printf("-- j회사 게임 출시 정보 --\n");
	printf(" 게임명   : %s\n", gameInfo2.name);
	printf(" 발매년도 : %d\n", gameInfo2.year);
	printf(" 가격     : %d\n", gameInfo2.price);
	printf(" 제작사   : %s\n\n", gameInfo2.company);
	
	// 구조체 배열
	struct GameInfo gameArray[2] = {
		{"랜덤뽑기", 2023, 1000, "i회사"}, 
		{"랜덤가차", 2023, 2000, "j회사"}
	};
	
	// 구조체 포인터
	struct GameInfo * gamePtr; // 미션맨
	gamePtr = &gameInfo1;
	printf("-- 미션맨회사 게임 출시 정보 --\n");
	// printf(" 게임명   : %s\n", (*gamePtr).name); // *Ptr
	// printf(" 발매년도 : %d\n", (*gamePtr).year);
	// printf(" 가격     : %d\n", (*gamePtr).price);
	// printf(" 제작사   : %s\n", (*gamePtr).company);
	
	printf(" 게임명   : %s\n", gamePtr->name); // *윗 코드와 똑같이 실행됨
	printf(" 발매년도 : %d\n", gamePtr->year);
	printf(" 가격     : %d\n", gamePtr->price);
	printf(" 제작사   : %s\n\n", gamePtr->company);
	
	// 구조체 안의 구조
	gameInfo1.friendGame = &gameInfo2;
	gamePtr = &gameInfo1;
	printf("-- friendgame회사 게임 출시 정보 --\n");
	// printf(" 게임명   : %s\n", (*gamePtr).name); // *Ptr
	// printf(" 발매년도 : %d\n", (*gamePtr).year);
	// printf(" 가격     : %d\n", (*gamePtr).price);
	// printf(" 제작사   : %s\n", (*gamePtr).company);
	
	printf(" 게임명   : %s\n", gamePtr->name); // *윗 코드와 똑같이 실행됨
	printf(" 발매년도 : %d\n", gamePtr->year);
	printf(" 가격     : %d\n", gamePtr->price);
	printf(" 제작사   : %s\n", gamePtr->company);
	
	// typedef
	// 자료형의 별명 지정
	int i = 1;
	typedef int A;
	typedef float B;
	A num = 3; // int i = 3; 과 같은 동작을 하고 있음
	B num2 = 3.23f; // int f =3.23f; 와 같은 동작을 하고 있음
	printf("\nA = %d\nB = %.3f\n", num, num2);
	
	typedef struct GameInfo gameInfo;
	gameInfo game1;
	game1.name = "한글 게임";
	game1.year = 2022;
	
	printf(" \n 게임명   : %s\n", game1.name);
	printf(" 발매년도 : %d\n", game1.year);
	
	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2023;
	
	printf(" \n 게임명   : %s\n", game2.name);
	printf(" 발매년도 : %d\n", game2.year);
	
	struct GameInformation game3;
	game3.name = "한글게임3";
	game3.year = 2024;
	
	printf(" \n 게임명   : %s\n", game3.name);
	printf(" 발매년도 : %d\n", game3.year);
	
	return 0;
}