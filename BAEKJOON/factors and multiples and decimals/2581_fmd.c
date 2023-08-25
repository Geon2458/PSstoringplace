#include <stdio.h>

int main(void){
	
	/*
	해결해야 하는 조건
	
	배열 arr에 숫자 m부터 n까지 저장
	
	배열 dec에 소수를 저장해서 최솟값을 비교하여 최솟값 저장 후 출력
	
	sum += 를 사용하여 소숫값을 모두 더하여 저장
	
	소수가 없을 경우 '-1' 출력
	*/
	
	int m, n, sum = 0, count = 0;
	int arr[10001], dec[10001];
	
	scanf("%d %d", &m, &n);
	
	int a = n-m+1;                                 // m부터 n까지의 숫자 개수
	
	for (int i = 0; i < a; i++){                   // 배열 arr[0]부터 arr[a-1]까지 m부터 n까지의 수를 저장
		arr[i] = m+i;
	}
	
	for (int i = 0; i < a; i++){
		int cnt = 0;
		for (int k = 1; k <= n; k++){              // 배열 arr의 수들의 약수를 구하기 위해 사용
			if (arr[i]%k == 0 && arr[i] >= k){     // 약수면 cnt 쓸데 없는 계산을 막기 위해 arr[i] >= k
				cnt++;
			}
		}
		if (cnt == 2){                              // 소수는 cnt가 2이므로
			count++;                                // 소수의 개수 count
			dec[count] = arr[i];                    // dec[1] 부터 소수인 arr[i]를 저장
			sum += arr[i];                          // 소수를 모두 더한 값
		}
	}

	int min = dec[1];                                // 최솟값을 구하기 위해 사용
	for (int i = 1; i < count; i++)
	{
		if (min > dec[i])                            // dec[i]의 값이 min보다 작으면
		{
			min = dec[i];                            // min에 dec[i]를 저장하여 최솟값 계산
		}
	}
	
	if (count == 0){                                  // count == 0이면 소수가 없다는 뜻이므로 '-1' 출력
		printf("-1\n");
	}
	else {
		printf("%d\n%d\n", sum, min);
	}
	
	return 0;
}