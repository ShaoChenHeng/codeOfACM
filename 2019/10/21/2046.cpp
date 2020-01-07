#include<stdio.h>

int main()
{
	int a[50]={1,2,3,5};
	int i,n;
	for(i=4;i<50;i++) a[i]=a[i-1]+a[i-2];
	while(scanf("%d",&n)!=EOF) printf("%d\n",a[n-1]);
	return 0; 
}