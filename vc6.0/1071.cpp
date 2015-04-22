#include<stdio.h>
#include<math.h>
int main()
{
	int x1,y1,r1,x2,y2,r2,k;
	double d1,d2,d3;
	scanf("%d%d%d", &x1,&y1,&r1);
	scanf("%d%d%d", &x2,&y2,&r2);
	scanf("%d",&k);
	d1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2 = r1-d1;
	d3=d2 + r2;
	if(d3 < (double)k)
		printf("Yes");
	else
		printf("No");
	return 0;
}
