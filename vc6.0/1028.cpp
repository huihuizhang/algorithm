#include<stdio.h>
#define N 1005
#define M 8193
int V[2][M],g[N][M];
int v[N],w[N];//内存weight  喜爱程度value
int prin(int gg[N][M],int i, int w);
void DPKnapsack(int w[], int v[],int n,int W);//动态规划算法
int main()
{	
	int n,W,i;
	//int ans[1005];//要保存的游戏
	scanf("%d%d",&n,&W);//输入 数目n和容量W
	for ( i = 1; i <= n; i++)
		scanf("%d",&w[i]);
	for ( i = 1; i <= n; i++)
		scanf("%d",&v[i]);
	DPKnapsack(w, v,n,W);
	prin(g[N][M],n,W);
	return 0;
}

int prin(int g[N][M],int i, int w)
{
	if (i==0||w==0)
	{
		printf("%d",i);
		return 0;
	}
	if (g[i][w]==1)
		prin(g[N][M],i-1,w-w[i]);
	else
		prin(g[N][M],i-1,w);
}

void DPKnapsack(int w[], int v[],int n,int W)
{
	int i,j;
	for (i = 0; i < w[1]; i++)
		V[1][i] = 0;
	for ( i = w[1] ; i <= W; i++)
	{
		V[1][i] = v[1];
		//if(v[i] >=0)
		//	V[1][i] = v[1];
		//else
		//	V[1][i] = 0;
	}
	for (i = 2; i<=n; i++)
	{
		for ( j = 0; j <= W; j++)
		{
			if (w[i] > j)
			{
				V[i%2][j] = V[(i - 1)%2][j];
				g[i][j] = 8;
			}
			else 
			{
				if (V[(i - 1)%2][j]  > V[(i - 1)%2][j - w[i]] + v[i])
				{
		 			V[i%2][j] = V[(i - 1)%2][j];
					g[i][j] = 8;
				}
				else
				{
					V[i%2][j] = V[(i - 1)%2][j - w[i]] +v[i];
					g[i][j] = 1;
				}
			}
		}
	}
}

