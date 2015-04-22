#include<stdio.h>
#define N 100005
double w[N],v[N];
void Greeyknap(double W,int n);
int partion(int p, int q);
void swap(int i ,int j);
void quicksort(int p, int q);

int main()
{
	int n,i;
	double W;
	scanf("%lf%d",&W,&n);
	for ( i = 1; i <=n; i++)
	{
		scanf("%lf%lf",&w[i],&v[i]);
	}
	Greeyknap(W,n);
	return 0;
}

int partion(int p, int q)
{ 
	 int i=p;
     int j=q+1;
     while(true)
     {
       while(v[++i]/w[i]> v[p]/w[p]);
       while(v[--j]/w[j]<v[p]/w[p]);
       if(i >= j) break;
       swap(i,j);
     }
     swap(p,j);
     return j;
}



void quicksort(int p, int q)
{
	int r;
     if(p<q)
     {
       r=partion(p,q);
       quicksort(p,r-1);
       quicksort(r+1,q);
     }
}


void swap(int i ,int j)
{
	double temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	temp = w[i];
	w[i] = w[j];
	w[j] = temp;
}

void Greeyknap(double W,int n)
{
	int i = 1;
	double ws= W;
	double sum = 0.0;
	double x[N];
	//order
	quicksort(1,n);
	while (ws>0 && i<=n)
	{
		x[i] = 1< (ws/w[i])? 1: (ws/w[i]);
		ws = ws - w[i]*x[i];
		sum = sum + v[i] * x[i];
		i++;
	}
	printf("%.6lf",sum);
	
}
