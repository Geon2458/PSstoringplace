#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char n[1001] = {0};
	int b, sum = 0;
	
	scanf("%s %d", n, &b);
	
	int s = strlen(n);
	
	double res;
	
	for (int k = 0; k < s; k++)
	{
		for (int i = 48; i <= 57; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				if (n[k] == i && n[k] )
				{
					n[k] = i%48;
				}
				else if (n[k] == j)
				{
					n[k] = j%55;
				}
			}
		}
	}

    for (int i = 0; i < s/2; i++)
	{
		int temp = n[s-1-i];
		n[s-1-i] = n[i];
		n[i] = temp;
	}

	for (int i = 0; i < s; i++)
	{
		res = pow (b, i);
		sum += n[i] * res;
	}
	
	printf("%d", sum);
	
	return 0;
}

// 다른 c online compiler 쓸 것