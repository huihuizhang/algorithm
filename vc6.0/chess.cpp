#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMEMNT 10 //存储空间分配增量
#define N 8
typedef struct _Point{
	int x;
	int y;
}Point;
typedef Point SElemType;
typedef int Status;
typedef struct _SqStack{
SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &s)
{
	//构造一个空栈 S
	s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	//存储分配失败
	if (!s.base)
		return OVERFLOW;
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack s, SElemType &e)
{
	//若栈不为空，用e返回s的栈顶元素，并返回OK；否则返回ERROR
	if (s.top == s.base)
		return ERROR;
	e = *(s.top - 1);
	return OK;
}

Status Push(SqStack &s, SElemType e)
{
	//插入元素e为新的栈顶元素
	if (s.top - s.base >= s.stacksize)
	{
		//栈满，追加空间
		s.base = (SElemType*) realloc(s.base, (s.stacksize + STACK_INIT_SIZE) * sizeof(SElemType));
		if (!s.base)
			return OVERFLOW;
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMEMNT;
	}
	*s.top++ = e;
	return OK;
}

Status Pop (SqStack &s, SElemType &e)
{
	if (s.top == s.base)
		return ERROR;
	e = * --s.top;
	return OK;
}

//马的走位
int HTry1[] = {-2, -1, 1, 2, 2, 1, -1, -2}; //x方向走位
int HTry2[] = {1, 2, 2, 1, -1, -2, -2, -1}; //y方向走位
//标识
int board[N][N] = {0}; //N * N 个棋盘
int step = 1; //已经走的步数
SqStack s[65]; //第step步的下一步的所有可能位置
SqStack s1; //临时栈


//函数定义
void GetOrdnance(Point &p); //获得坐标
void Exit(Point p); //计算下一步
int Number(Point p); //找出当前位置下一步的各种可能位置，计算可能之和
void Next(Point p); //找出各个位置并将其步数记录
bool Legal(Point p); //判断是否可行
void PrintChessBoard(int board[N][N]); //打印棋盘

int main()
{
	Point p;
	GetOrdnance(p);
	InitStack(s1);
	Next(p);
	PrintChessBoard(board);
return 0;
}

void GetOrdnance(Point &p)
{
	printf("输入 x ( 0 - %d ), y ( 0 - %d )\n", N - 1, N - 1);
	scanf("%d %d", &p.x, &p.y);   //判断输入是否合法
	while (! ((p.x >= 0) && (p.x < N ) && (p.y >= 0) && (p.y < N )) )
	{
printf("输入不合法，请重新输入\n");
printf("输入 x ( 0 - %d ), y ( 0 - %d )\n", N - 1, N -1);
		scanf("%d %d", &p.x, &p.y);
}
}

void PrintChessBoard(int board[N][N])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%5d", board[i][j]);
		}
		printf("\n");
	}
}

int Number(Point p)
{
	Point p1;
	int j = 0;
	for (int i = 0; i < 8; i++)
	{
		p1.x = p.x + HTry1[i];
		p1.y = p.y + HTry2[i];
		if (Legal(p1))
		{
			j++;
		}
	}
	return j;
}
void Next(Point p)
{
	Point p1, p2; //p2存储下一步要走的位置 p1存储当前位置
	p2=p;
	while(step < N * N)
	{
		InitStack(s[step]);
		board[p.x][p.y] = step;
		Push(s1, p); //将当前位置压入s1
		Exit(p);
		Pop(s[step], p2); 
		if ((s[step].base == s[step].top && Number(p2) == 0) && step != N * N - 1) //s[step]为空栈 下一步不能走了 步数没有到64
		{ 
			Pop(s1, p1); //把当前位置从临时栈s1里pop出来
			board[p1.x][p1.y] = 0; 
			--step; 
			while (s[step].base == s[step].top) 
			{
				Pop(s1, p1); 
				board[p1.x][p1.y] = 0;
				step--; //一直回溯到下步能走为止
			}
			Pop(s[step], p2); //换一种下一步的走法
			step++;
			p=p2;
			
		}
		else if (Number(p2) == 0 && s[step].base != s[step].top)
		{
			Pop(s[step], p2); 
			step++;
			p=p2;
			
		}
		else
		{
			step++;
			p=p2;
			
		}
	}
	board[p.x][p.y] = step;
}

void Exit(Point p)
{
	Point temp;
	Point p1;
	int j = 0;
	Point ap[8] = {0};
	for (int i = 0; i < 8; i++)
	{
		p1.x = p.x + HTry1[i];
		p1.y = p.y + HTry2[i];
		if (Legal(p1))
		{
			ap[j] = p1;
			j++;
		}
	}//将下一步的可能位置存储在ap[]中
	for (int count = 0; count < Number(p) - 1; count++)
	{
		for (int k = 0; k < Number(p) - 1; k++)
		{
			if (Number(ap[k]) < Number(ap[k+1])) //从大到小排列
			{
				temp = ap[k+1];
				ap[k+1] = ap[k];
				ap[k] = temp;
			}
		}
	}
	for (int t = 0; t < Number(p); t++) 
	{
		Push(s[step], ap[t]); //从大到小压入s[step]栈中，pop的时候就是从小到大 
	}
}

bool Legal(Point p)
{
	if ((p.x >= 0) && (p.x < N) && (p.y >= 0) && (p.y < N) && (board[p.x][p.y] == 0))
		return true;
	else
		return false;
}
