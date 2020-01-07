#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char *argv[]) {
	double i;
	int n=12;
	double sum=0.0;
	while(n--)
	{
		scanf("%lf",&i);
		sum+=i;
	}
	printf("$%.2lf\n",(double)((int)(sum/12*100.0+0.5))/100.0);
	
	
	return 0;
}
