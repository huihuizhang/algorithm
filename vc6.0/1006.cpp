#include<stdio.h>
void main()
{
	char a[1000],b[1000];
	int a1[1000],b1[1000],c[1000];
	int i,j,k,x,jin,n1,n2,n,count;
	scanf("%s%s",a,b);
	for (i = 0; a[i] != '\0'; i++)
	{
		a1[i]=a[i]-48;
		//printf("%d ",a1[i]);
	}
	n1=i;
	for (i = 0; b[i] != '\0'; i++)
	{
		b1[i]=b[i]-48;
		//printf("%d ",b1[i]);
	}
	n2=i;
	n= (n1 > n2 ? n1 : n2 )+1; 
	jin = 0;
	k=0;
	//printf("%d %d %d\n", n1,n2,n);
	count = 0;
	for (i = n1-1, j = n2-1 ,k = n-1; i>=0 && j>=0 ; i--, j--,k--)
	{
		x  = a1[i] + b1[j] + jin ;
		c[k] = x %10;
		jin  = x/10;
		//printf ("%d %d %d\n", x,c[k],jin);
		count++;
	}
	//printf ("%d %d\n", i,j);
	while ( i >= 0)
	{
		x = a1[i--] + jin ;
		c[k--] = x%10;
		jin = x/10;
		//printf ("%d %d %d\n", x,c[k],jin);
		count++;
	}
		while ( j >= 0)
	{
		x = b1[j--] + jin ;
		c[k--] = x%10;
		jin = x/10;
		//printf ("%d %d %d\n", x,c[k],jin);
		count++;
	}
	if (jin)
	{
		c[k] = jin;
	for ( i = 0; i <= count ; i++ )
	{
		printf("%d", c[i]);
	}
	}
	else
		for ( i = 1; i <= count ; i++ )
	{
		printf("%d", c[i]);
	}


	
	
}