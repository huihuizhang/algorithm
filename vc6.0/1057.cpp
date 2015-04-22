#include<stdio.h>
#define N 1000000000;
int  main()
{
	int i,j,k,m,n,c,min;
	int s[110],t[110];
	scanf ("%d%d%d",&m,&n,&c);
	for ( i= 0; i<m; i++)
		scanf("%d%d",&s[i],&t[i]);
	while (c<n)
	{
		min=s[0];
		for (i=0; i<m; i++) //找到最小的s[i]
		{
			if (s[i]< min)
			{
				min = s[i];
				k = i;
				printf("%d",min);
				printf("abc");
			}
		}
		c++;
		if(s[k]>N)
			break;
		else
			s[k] = s[k] + t[k];
	}
	if (s[k]>N)
		printf("no");
	else
		printf("%d",k+1);
	return 0;
}