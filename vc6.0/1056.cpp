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
		if(ener >= 0)//�о���ʱִ��
		{
			if(ener <= 2)//����<=2���������˯��ſ��
			{
				//����?ſ��?�˯ ѡ�����ֵ
				max[i] = max[i-1] > max[i-1]+conten[i]/2 ? max[i-1] : max[i-1]+conten[i]/2;
				//˯
				ener = ener - 1;//ſ
				ener = ener  + k*(k - 1)/2 ;//˯
				
			}
			else //�������Σ�����ѡ��
			{
				
				max[i] = max[i-1] > max[i-1]+conten[i]/2 ? max[i-1] : max[i-1]+conten[i]/2;
				
				ener = ener - 3;//��
				ener = ener - 1;//ſ
				ener = ener  + k*(k - 1)/2 ;//˯
			}
		}
	}	
	printf("%d",max[45]);
}