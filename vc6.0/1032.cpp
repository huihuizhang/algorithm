#include<stdio.h>
#define N 1010
int main()
{
	int i,j,n,e1,e2,x1,x2;
	int a1[N],a2[N],t1[N],t2[N];
	int f1[N],f2[N],f;
	scanf("%d", &n);
	scanf("%d%d%d%d", &e1, &e2, &x1, &x2);
	for( i = 1; i <=n ; i++)
		scanf("%d",&a1[i]);
	for( i = 1; i <=n ; i++)
		scanf("%d",&a2[i]);
	for( i = 1; i < n ; i++)
		scanf("%d",&t1[i]);
	for( i = 1; i < n ; i++)
		scanf("%d",&t2[i]);
	f1[1] = e1 + a1[1];
	f2[1] = e2 + a2[1];
	for( j = 2; j <=n; j++)
	{
		if(f1[j-1] + a1[j] <= f2[j-1] + t2[j-1] + a1[j])
			f1[j] = f1[j-1] + a1[j];

		else
			f1[j] = f2[j-1] + t2[j-1] + a1[j];
		if(f2[j-1] + a2[j] <= f1[j-1] + t1[j-1] + a2[j])	
			f2[j] = f2[j-1] + a2[j];	
		else
			f2[j] = f1[j-1] + t1[j-1] + a2[j];
		
	}
	if (f1[n] + x1 <= f2[n] + x2)
		f = f1[n] + x1;
	else
		f = f2[n] + x2;
	printf("%d\n",f);
	return 0;
}
