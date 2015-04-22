#include <stdio.h>
#include<math.h>
int main()
{
	int n,i,j,key,a[1002];
	scanf("%d", &n);
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for ( i = 1; i < n; i++)
	{
		key = a[i];
		j = i-1;
		while ( a[j] > key && j >=0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	for ( i = 0; i < n-1 ; i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d",a[n-1]);
	return 0;
}