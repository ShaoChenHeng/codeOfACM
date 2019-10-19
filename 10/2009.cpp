#include <cstdio>
#include <cmath>

int m;
double n;

int main()
{
    int a,b;    
    while(scanf("%lf %d",&n,&m) != EOF)
    {
        double sum = 0;
       for ( int i = 0; i < m; i ++ )
       {
           sum += n;
           n = sqrt(n);
       }
       printf("%.2lf\n",sum);
    }
    return 0;
}
