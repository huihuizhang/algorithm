#include <stdio.h>
#include<limits.h>
int a[101][101];
int w[101];
bool b[101];
int n;

void Prim()
{
    int i,j,t,tmp,tim=0; 
    for(i=1;i<=n;i++)
    {
      w[i]=a[1][i];
      b[i]=false;
    }
    b[1]=true;//��һ�в�����
    for(i=2;i<=n;i++)//�ӵ�һ�е������ڶ���
    {
      //t=1;
      tmp=INT_MAX;
      for(j=2;j<=n;j++)//�ӵĶ���ֵ��ʼ��
      {
        if(!b[j]&&w[j]<tmp)
        {
          t=j;
          tmp=w[j];
        }
      }
      tim+=tmp;
      b[t]=true;
      
      for(j=2;j<=n;j++)
      {
        if(!b[j]&&w[j]>a[t][j])
          w[j]=a[t][j];
      }
    }
    
    printf("%d",tim);
}

int main()
{
    int i,j;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
    
    Prim();

    return 0;
}