#include<stdio.h>
void main()
{
	int  a,b,temp;
	printf("Enter a=");
	scanf("%d",&a);
	printf("Enter b=");
	scanf("%d",&b);
	
	temp=a;
	a=b;
	b=temp;
	printf("\nAfter swapping");
	printf("\na=%d",a);
	printf("\nb=%d",b);
}
