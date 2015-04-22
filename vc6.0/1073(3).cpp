#include<stdio.h>
#include<malloc.h>
#define max 20

typedef struct node
{
	int data;
	char ch[45];
	struct node *next;
}Node;

typedef struct
{
	Node tou[max];
	int length;
}Graph;

typedef struct
{
	int data[max],length;
}Stack;
Node *houji(Node *head,int n);
void createTu(Graph *tu,int j);
void print(Graph tu);
void tpsort(Graph *tu);
void Push(Stack *z, int n);
void Updata(Graph *tu, int n);
//void Get(Stack z);
void Get(Stack z, Graph *tu);
Node *shanchu(Node *head, Node *p1);

void main()
{
	Graph tu;
	int i,n;
	puts("ÊäÈë¿É³ÂÊö£º");
	scanf("%d",&n);
	for ( i =1; i<n; i++)
		scanf("%s",&tu.tou[i].ch);
	createTu(&tu,n);
	print(tu);
	tpsort(&tu);
}

void tpsort(Graph *tu)
{
	int i,j,k,g,flag = 0,t,m1,m2,m=0;
	Stack z;
	z.length = 0;
	while((!flag) && (m<tu->length))
	{
		m++;
		for (i = 1; i<tu->length; i++)
		{
			t = 0;
			for ( j = 1; j<=z.length; j++)
			{
				if (i==z.data[j])
					t=1;
			}
			if(tu->tou[i].next == NULL && t==0)
			{
				Push(&z,i);
				Updata(tu,i);
				//print(*tu);
				break;
			}
		}
		m1=1;
		for (g=1; g<=tu->length; g++)
		{
			m2=0;
			for ( k = 1; k<=z.length;k++)
			{
				if(z.data[k]==g)
					m2=1;
			}
			if(m2 == 0)
				m1 = m2;
		}
		flag = m1;
		//printf("%-8s",tu->tou[g].ch);break;
	}
	if(m>tu->length)
		printf("Impossible!!!");//puts("@@");
	else
		Get(z,tu);puts("");
}

void Get(Stack z, Graph *tu)
{
	int i;
	for ( i = 1; i<=z.length; i++)
	{
		printf("%s  ",tu->tou[z.data[i]].ch);
	}
}

void Updata(Graph *tu,int n)
{
	int i;
	Node *p;
	for ( i = 1; i<=tu->length; i++)
	{
		p= tu->tou[i].next;
		while (p!=NULL)
		{
			if(p->data==n)
			{
				tu->tou[i].next == shanchu(tu->tou[i].next,p);break;
			}
			p=p->next;
		}
	}
}

Node *shanchu (Node *head, Node *p1)
{
	Node *p,*p2,*p3;
	p=p2=head;
	if (p1->data == head->data)
	{
		return head ->next;
	}
	else
	{
		p=p->next;
		while (p!=NULL)
		{
			if ( p->data == p1-> data)
			{
				p3 = p->next;
				p2->next = p3;
				break;
			}
			p = p->next;
			p2= p2->next;
		}
	}
	return head;
}

void Push(Stack *z, int n)
{
	z->length++;
	z->data[z->length] = n;
}

void print(Graph tu)
{
	int i;
	Node *p;
	for ( i = 1; i<=tu.length; i++)
	{
		printf("%d",i);
		p=tu.tou[i].next;
		while (p!=NULL)
		{
			printf("%d",p->data);
			p=p->next;
		}
		puts("");
	}
}

void creatTu(Graph *tu, int n)
{
	int i,d,e,x;
	char c;
	Node *p;
	for (i = 1; i<=n; i++)
	{
		tu->tou[i].next = NULL;
	}
	tu->length = 0;
	for ( i = 1; i<=n; i++)
	{
		scanf("%d",&x);
		tu->length ++;
		scanf("%d",&d);
		tu->tou[tu->length].data=d;
		scanf("%d",&e);
		while (e != 0 && e<=n)
		{
			tu->tou[tu->length].next = houji(tu->tou[tu->length].next,e);
			scanf("%d",&e);
		}
	}
}

Node *houji(Node *head,int n)
{
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	p->data = n;
	p->next = head;
	return p;
}

