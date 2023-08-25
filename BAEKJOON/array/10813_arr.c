// #include <stdio.h>

// int main(void)
// {
// 	int n, m, a, b, temp;
// 	int arr[101];
	
// 	scanf("%d %d", &n, &m); // 바구니의 갯수와 공을 바꿀 횟수

// 	for (int i = 1; i <= n; i++)
// 	{
// 		arr[i] = i;
// 	}
// 	for (int i = 1; i <= m; i++) // m번 공을 바꾼다
// 	{
// 		scanf("%d %d", &a, &b); // a번 바구니와 b번 바구니에 들어 있는 공을 교환 한다
		
// 		temp = arr[a];
// 		arr[a] = arr[b];
// 		arr[b] = temp;
// 	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
	
// 	return 0;
// }

#include <stdio.h>

void swap(int * a, int * b);

int main(void)
{
    int n, m, a, b;
    int arr[101];
    
    scanf("%d %d", &n, &m);       // 바구니의 갯수와 공을 몇번 바꿀지
    
    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;               // 1부터 1씩 커지는 배열 
    }
    for(int i = 1; i <= m; i++)   // 공을 몇번 바꿀지
    {
        scanf("%d %d", &a, &b);   // 바꾸려는 두 개의 숫자
        swap(&arr[a], &arr[b]);   // 두 개의 숫자를 바꾼다
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);    // 바꾼 배열을 출력
    }
    return 0;
}

void swap(int * a, int * b)   // 두 개의 숫자를 바꾸기 위한 코드
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  