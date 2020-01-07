#include <cstdio>

using namespace std;

int n;

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        while ( n -- )
        {
            int m;
            scanf("%d",&m);
            double max = -10000;
            double num;
            for( int i = 0; i < m; i ++ ) 
            {
                scanf("%lf",&num);
                if ( num > max ) max = num;
            }
            printf("%.2lf\n",max);
        }
        
        
    }
    return 0;
}
