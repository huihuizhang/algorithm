#include<stdio.h>
#define N = 20;
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
	char classname[45];
	ArcNode *firstarc;
	int code;
}VNode;

typedef struct {
	VNode list[N];
	int vexnum,arcnum;
}ALgraph;

ALgraph G;

void CreatGraph(ALgraph &G)
{
	scanf("%d",&G.vexnum);
	for ( i = 1; i <= G.vexnum ; i++)
	{
		scanf("%s",&G.list[i].classname);
		getchar();
		G.list[i].firstarc = NULL;
		G.list[i].code = i;
	}
	for ( i = 1; i <= G.vexnum; i++)
	{
		scanf("%d",&needfinish[i]);
		for ( i = 1; i <= needfinish[i] ; i++)
		{
			scanf("%d",&x)
		}
	}
}

void main()
{
	int n,i;
	CreatGraph(G);
	
}