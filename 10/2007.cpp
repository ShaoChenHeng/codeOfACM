#include <cstdio>
#include <cmath>

int n,m;

int main()
{
    int a,b;    
    while(scanf("%d %d",&m,&n) != EOF)
    {
        int sum1 = 0,sum2 = 0;
        if( m > n ){int t = m; m = n; n = t;}
        for ( int i = m; i <= n; i++ )
        {
            if ( i % 2 == 0 ) sum2 += pow(i,2);
            else sum1 += pow(i,3);
        }
        printf("%d %d\n",sum2,sum1);
    }
    return 0;
}
