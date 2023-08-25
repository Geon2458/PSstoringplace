#include <stdio.h>
#include <string.h>

int main(void)
{
	char sub[52] = {0};
	char rat[21] = {0};
	double sum[21], c = 0;
	double credit, avge = 0, p = 0;
	int cnt = 0;
	
	for (int i = 0; i < 20; i++)
	{
		scanf("%s %lf %s", sub, &credit, rat);
		double s = strlen(rat);
		
		for (int j = 0; j < s; j++)
		{
			if (rat[j] == 65 && rat[j+1] == 43)
			{
				sum[i] = credit*4.5;
			}
			else if (rat[j] == 65 && rat[j+1] == 48)
			{
				sum[i] = credit*4.0;
			}
			else if (rat[j] == 66 && rat[j+1] == 43)
			{
				sum[i] = credit*3.5;
			}
			else if (rat[j] == 66 && rat[j+1] == 48)
			{
				sum[i] = credit*3.0;
			}
			else if (rat[j] == 67 && rat[j+1] == 43)
			{
				sum[i] = credit*2.5;
			}
			else if (rat[j] == 67 && rat[j+1] == 48)
			{
				sum[i] = credit*2.0;
			}
			else if (rat[j] == 68 && rat[j+1] == 43)
			{
				sum[i] = credit*1.5;
			}
			else if (rat[j] == 68 && rat[j+1] == 48)
			{
				sum[i] = credit*1.0;
			}
			else if (rat[j] == 70)
			{
				sum[i] = credit*0;
			}
			else
			{
				break;
			}
			if (rat[j] != 80)
			{
				c += credit;
			}
			avge += sum[i];
		}
	}
	p += c;
	
	if (p > 0 && p < 0.000001)
	{
		printf("0.000000");
	}
	
	else
	{
		printf("%lf", avge/p);
	}
	
	return 0;
}