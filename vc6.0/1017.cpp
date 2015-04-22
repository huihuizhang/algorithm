#include<stdio.h>
#include<math.h>
int tile = 0;
int board[1100][1100];
int main()
{
	int TileBoard (int tr,int tc, int dr, int dc, int size);
	int i,j,n,x,y;
	scanf("%d",&n);
	scanf("%d%d", &x, &y);
	board[x][y]=0;
	TileBoard(1,1,x,y,pow(2,n)); //左上角格子，残缺各自，棋盘大小
	for (i = 1; i <= pow(2,n); i++)
	{
		for( j = 1; j <= pow (2,n); j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int TileBoard (int tr,int tc, int dr, int dc, int size)
{
	int t,s;	
	if(size==1)
		return 0;
	tile = tile +1 ;
	t = tile;
	s= size/2;
	if( (dr < tr + s) && (dc < tc +s))
		TileBoard (tr, tc,dr, dc,s);
	else
	{
		board[tr + s - 1][tc + s - 1] = t;
		TileBoard (tr, tc,tr+s-1, tc+s-1,s);
	}
	if( (dr < tr + s )&& (dc >= tc +s))
		TileBoard (tr, tc+s,dr, dc,s);
	else
	{
		board[tr + s - 1][tc + s] = t;
		TileBoard (tr, tc+s,tr+s-1, tc+s,s);
	}
	if( (dr >= tr + s) && (dc < tc +s))
		TileBoard (tr+s, tc,dr, dc,s);
	else
	{
		board[tr + s][tc + s - 1] = t;
		TileBoard (tr + s, tc,tr + s, tc + s - 1,s);
	}
	if( (dr >= tr + s )&& (dc >= tc +s))
		TileBoard (tr + s, tc + s,dr, dc,s);
	else
	{
		board[tr + s][tc + s] = t;
		TileBoard (tr + s, tc+s,tr + s, tc + s,s);
	}
}