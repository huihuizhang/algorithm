#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMEMNT 10 //存储空间分配增量
#define N 8
typedef int SElemType;
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

bool StackEmpty(SqStack s)
{
	if(s.top==s.base)
		return true;//为空
	else
		return false;//不为空
}

SqStack s;
char classname[510][45];
int degree[510],needfinish[510],code[510][510],print[510];
int main()
{
	int i,j,k,vexnum,count;
	scanf("%d",&vexnum);
	for ( i = 1; i<= vexnum; i++)
	{
		scanf("%s",classname[i]);
		getchar();
	}
	//for ( i = 1; i<=vexnum; i++)
	//	printf("%s\n",classname[i]);
	for ( i = 1; i<=vexnum; i++)
	{
		scanf("%d",&needfinish[i]);
		if(needfinish)
		{
			for ( j = 1; j <= needfinish[i]; j++)
			{
				scanf("%d",&code[i][j]);
			}
		}
		degree[i] = needfinish[i];
	}
	InitStack(s);
	for ( i = 0; i<= vexnum; i++)
	{
		if(!degree[i])
			Push(s,i);
	}
	count = 0;
	while ( !StackEmpty(s))
	{
		Pop(s,i);
		count++;
		//printf("%s ",classname[i]);
		print[count] = i;
		//找出所有与i有关的结点，深度减一
		for ( j =1; j<=vexnum ;j++)
		{
			if(j!=i && needfinish[j])
			{
				for ( k = 1; k <= needfinish[j] ; k++)
				{
					if(k==i)
						if(!(--degree[j]))
							Push(s,j);
				}
			}
		}
	}
	if(count < vexnum)
		printf("Impossible!");
	else
	{
		for ( i = 1; i<count; i++)
			printf("%s ",classname[print[i]]);
		printf("%s",classname[print[count]]);
	}
	return 0;	
}