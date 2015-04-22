#include<stdio.h>
//类似背包问题
void findmoney( double money,double value[],int change[]);
int main()
{
	int i, n,change[6];
	double value[6];
	double money; //需要找的零钱
	value[0] = 50;
	value[1] = 10;
    value[2] = 5;
	value[3] = 1;
	value[4] = 0.5;
	value[5] = 0.1;
	scanf("%d",&n);
	money = 100 - n*2.5;
	for ( i =0; i<6; i++)
	{
		scanf("%d",&change[i]);
	}
	findmoney(money,value,change);
	return 0;
}

void findmoney( double money,double value[],int change[])
{
	int num,sum,i,geshu;
	int n[6];
	for (i = 0; i<6; i++)
		n[i] = 0;
	if(money == 0)
		num = 0;
	else
	{
		for (i = 0; i<6 ;i++)
		{
			if(money >= value[i])
			{
				//printf("bingo! %d\n",money);
				geshu = money/value[i];
				if (geshu <= change[i])
					n[i] = geshu;
				else
					n[i] = change[i];
				money = money - n[i] * value[i];
			//	printf("geshu %d qianshu %d shengqian %d\n",n[i],money,value[i]);
				
			} 
		}
	}
	i=-1;
	if (money!=0)
		printf("%d\n",i);
	else
	{
		sum = 0;
		//for ( i = 1; i<=6;i++)
	//		printf("%d ",n[i]);
	//	printf("aaaa\n");
		for ( i =0; i<6; i++)
		{
			if (n[i]!=0)
			{
			//	printf("%d %d\n",n[i],i);
				sum = sum + n[i];
			}
		}
		printf("%d\n",sum);
	}
}