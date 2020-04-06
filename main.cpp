#include <stdio.h>
#include <stdlib.h>

void maxsum(int n, int a[100])
{
	int i, max, sum=0;
	max = a[0];
	for (i = 0; i < n; i++)
	{
		if (max> 0)
			 sum= sum+a[i];
		else
			sum = a[i];
		if (max < sum)
			max = sum;
	}
	if (max < 0)
	{
		printf("0");
	}
	else
	{
		printf("%d", max);
	}
}
int main()
{
	int n, a[100],i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	maxsum(n, a);
}
