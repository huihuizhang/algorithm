#include<stdio.h>
int main()
{
	int content[48];
	int ener,i;
	scanf("%d",&ener);
	for ( i = 1; i<=45; i++)
		scanf("%d",&content[i]);
	findMaxConten(content,ener);
	return 0;
}
void findMaxConten(int content[],int ener)
{
	double max[48];
	max[0] = 0;
	for ( i = 1; i<= 45; i++)
	{
		if(ener >= 0)//有精力时执行
		{
			if(ener <= 2)//精力<=2，发呆？瞌睡？趴着
			{
				//发呆?趴着?瞌睡 选择最大值
				max[i] = max[i-1] > max[i-1]+conten[i]/2 ? max[i-1] : max[i-1]+conten[i]/2;
				//睡
				ener = ener - 1;//趴
				ener = ener  + k*(k - 1)/2 ;//睡
				
			}
			else //可以听课，进行选择
			{
				
				max[i] = max[i-1] > max[i-1]+conten[i]/2 ? max[i-1] : max[i-1]+conten[i]/2;
				
				ener = ener - 3;//听
				ener = ener - 1;//趴
				ener = ener  + k*(k - 1)/2 ;//睡
			}
		}
	}	
	printf("%d",max[45]);
}