#include<stdio.h>
#include<math.h>
int main(){
	double i,a,b,d=0;
	double n=pow(2,-8);
	scanf("%lf%lf",&a,&b);

	printf("%lf\n",n);
	for(i=a;i<=b;);
    {
		printf("%lf\n",a);
		printf("%lf\n",b);
        d+=(n)/6*(sin(i)/i+4*sin((2*i+n)/2)/((2*i+n)/2)+sin(i+n)/(i+n));
		i=i+n;
        printf("%lf %lf\n",d,i); 
    }
	printf("%lf\n",d);
	
return 0;
}