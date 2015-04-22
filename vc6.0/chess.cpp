#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMEMNT 10 //�洢�ռ��������
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
	//����һ����ջ S
	s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	//�洢����ʧ��
	if (!s.base)
		return OVERFLOW;
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack s, SElemType &e)
{
	//��ջ��Ϊ�գ���e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (s.top == s.base)
		return ERROR;
	e = *(s.top - 1);
	return OK;
}

Status Push(SqStack &s, SElemType e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (s.top - s.base >= s.stacksize)
	{
		//ջ����׷�ӿռ�
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

//�����λ
int HTry1[] = {-2, -1, 1, 2, 2, 1, -1, -2}; //x������λ
int HTry2[] = {1, 2, 2, 1, -1, -2, -2, -1}; //y������λ
//��ʶ
int board[N][N] = {0}; //N * N ������
int step = 1; //�Ѿ��ߵĲ���
SqStack s[65]; //��step������һ�������п���λ��
SqStack s1; //��ʱջ


//��������
void GetOrdnance(Point &p); //�������
void Exit(Point p); //������һ��
int Number(Point p); //�ҳ���ǰλ����һ���ĸ��ֿ���λ�ã��������֮��
void Next(Point p); //�ҳ�����λ�ò����䲽����¼
bool Legal(Point p); //�ж��Ƿ����
void PrintChessBoard(int board[N][N]); //��ӡ����

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
	printf("���� x ( 0 - %d ), y ( 0 - %d )\n", N - 1, N - 1);
	scanf("%d %d", &p.x, &p.y);   //�ж������Ƿ�Ϸ�
	while (! ((p.x >= 0) && (p.x < N ) && (p.y >= 0) && (p.y < N )) )
	{
printf("���벻�Ϸ�������������\n");
printf("���� x ( 0 - %d ), y ( 0 - %d )\n", N - 1, N -1);
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
	Point p1, p2; //p2�洢��һ��Ҫ�ߵ�λ�� p1�洢��ǰλ��
	p2=p;
	while(step < N * N)
	{
		InitStack(s[step]);
		board[p.x][p.y] = step;
		Push(s1, p); //����ǰλ��ѹ��s1
		Exit(p);
		Pop(s[step], p2); 
		if ((s[step].base == s[step].top && Number(p2) == 0) && step != N * N - 1) //s[step]Ϊ��ջ ��һ���������� ����û�е�64
		{ 
			Pop(s1, p1); //�ѵ�ǰλ�ô���ʱջs1��pop����
			board[p1.x][p1.y] = 0; 
			--step; 
			while (s[step].base == s[step].top) 
			{
				Pop(s1, p1); 
				board[p1.x][p1.y] = 0;
				step--; //һֱ���ݵ��²�����Ϊֹ
			}
			Pop(s[step], p2); //��һ����һ�����߷�
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
	}//����һ���Ŀ���λ�ô洢��ap[]��
	for (int count = 0; count < Number(p) - 1; count++)
	{
		for (int k = 0; k < Number(p) - 1; k++)
		{
			if (Number(ap[k]) < Number(ap[k+1])) //�Ӵ�С����
			{
				temp = ap[k+1];
				ap[k+1] = ap[k];
				ap[k] = temp;
			}
		}
	}
	for (int t = 0; t < Number(p); t++) 
	{
		Push(s[step], ap[t]); //�Ӵ�Сѹ��s[step]ջ�У�pop��ʱ����Ǵ�С���� 
	}
}

bool Legal(Point p)
{
	if ((p.x >= 0) && (p.x < N) && (p.y >= 0) && (p.y < N) && (board[p.x][p.y] == 0))
		return true;
	else
		return false;
}
