#include<stdio.h>
#include<limits.h>
int dis[13][13];
int n, fill[13] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
int  findmin(int i);
int main()
{
	int i,j,sum,r;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j<=n ; j++)
		{
			scanf("%d",&dis[i][j]);
		}
	}
	j = findmin(1);
	fill[1] = 0;
	sum = dis[1][j];
	//printf("%d\n",sum);
	for (i = 1; i<n-1 ;i++)
	{
		r = findmin(j);
		fill[r] = 0;
		sum = sum + dis[j][r];
		//printf("%d %d\n",dis[j][r],sum);
		j = r;
	}
	//r = findmin(j);
	//printf("%d %d\n",r,sum);
	sum = sum + dis[r][1];
	//printf("%d %d\n",r,sum);
	printf("%d",sum);
	return 0;
}

int  findmin(int i)
{
	int min,col,j;
	min = INT_MAX;
	for( j =1; j<=n; j++)
	{
		if (dis[i][j] < min && dis[i][j]  && fill[j] )
		{
			min = dis[i][j];
			col = j;
		}
	}
	return col;
}