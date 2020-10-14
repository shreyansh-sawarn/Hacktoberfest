#include<stdio.h>
void main()
{
	int i,j,k,m1[3][3],m2[3][3],mul[3][3];
	printf("Enter first matrix:-\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			scanf("%d",&m1[i][j]);
		}		
	}
	printf("Enter second matrix:-\n");	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			scanf("%d",&m2[i][j]);
		}		
	}	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			mul[i][j]=0;
			for(k=0;k<=2;k++)
			{
				mul[i][j]=mul[i][j]+(m1[i][k]*m2[k][j]);			
			}
		}	
	}
	printf("Multiplication of matrices:-\n");		
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%d	",mul[i][j]);
		}
		printf("\n");		
	}
}
