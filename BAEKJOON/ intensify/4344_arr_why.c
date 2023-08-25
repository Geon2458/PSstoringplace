#include <stdio.h>

int main(void)
{
	int test, num;
	double arr[1001];  //.......int arr[1001]과 sum의 출력 값이 다른 이유를 모르겠습니다.
	double aver[1001];
	
	scanf("%d", &test); // test case의 개수 C개
	
	for (int i = 0; i < test; i++)
	{
		double sum = 0;
		double cnt = 0.00;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%le", &arr[j]);
			sum += arr[j]/num;
		}
		for (int j = 0; j < num; j++)
		{
			if (sum < arr[j])
			{
				cnt++;
			}
		}
		printf("%.3lf%%\n", (cnt/num)*100);
	}

	return 0;
}
/*
int arr[1001]
2
3 70 90 80
79.000000 66.667% ...............?
3 70 90 81
80.000000 66.667% ...............?

double arr[1001]
2
3 70 80 90
80.000000 33.333%
3 70 81 90
80.333333 66.667%
*/