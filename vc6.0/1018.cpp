#include <stdio.h>   
int main()   
{ 
	int n, m, t; 
	int a[5], b[5], c[5], v[5]; 
	scanf("%d", &t);
	while(t--)
	{   
		scanf("%d%d", &n, &m);
		a[1] = 1; a[2] = 1; a[3] = 1; a[4] = 0;   
		b[1] = 1; b[2] = 0; b[3] = 0; b[4] = 1;   
		if(n == 0)  {printf("0\n"); continue;}   
		while(n)   
		{   
			if(n & 1)     
			{   
				c[1] = (a[1] * b[1] + a[2] * b[3]) % m;   
				c[2] = (a[1] * b[2] + a[2] * b[4]) % m;   
				c[3] = (a[3] * b[1] + a[4] * b[3]) % m;   
				c[4] = (a[3] * b[2] + a[4] * b[4]) % m;   
				b[1] = c[1]; b[2] = c[2]; b[3] = c[3]; b[4] = c[4];   
			}   
			v[1] = (a[1] * a[1] + a[2] * a[3]) % m;   
			v[2] = (a[1] * a[2] + a[2] * a[4]) % m;   
			v[3] = (a[3] * a[1] + a[4] * a[3]) % m;   
			v[4] = (a[3] * a[2] + a[4] * a[4]) % m;   
			a[1] = v[1]; a[2] = v[2]; a[3] = v[3]; a[4] = v[4];   
			n >>= 1;   
		}
		printf("%d\n", c[2]);
    }   
	return 0;   
} 