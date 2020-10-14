#include <stdio.h>
int sumanti(int a[][100],int,int);
int main()
{
    int a[100][100],r,c,i,j;
    printf("enter the number of rows:");
    scanf("%d",&r);
    printf("enter the number of columns:");
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    sumanti(a,r,c);
}
int sumanti(int a[][100],int r,int c)
{
    int s[100],i,j,sum=0,k=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)    
        {
            if((i+j)==r-1)
            {
                s[i]=a[i][j];
                sum=sum+a[i][j];
            }
        }
    }
    printf("the sum of the antidiagonal elements is:%d\n",sum);
}
