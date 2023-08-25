#include <stdio.h>

int main(void)
{
	int n;
	int arr[1001];
	double sum = 0;
	
	scanf("%d", &n); // 시험 본 과목의 갯수
	
	for (int i = 0; i < n; i++) // 각 과목들의 점수
	{
		scanf("%d", &arr[i]);
	}
	
	double max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		sum += arr[i]/max*100;
	}
	
	printf("%.5f", sum/n);
	
	return 0;
}