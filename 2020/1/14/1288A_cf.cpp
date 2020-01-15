#include <bits/stdc++.h>

using namespace std;

long long int T, n, d;

int main()
{
    scanf("%lld", &T);
    while ( T -- )
    {
        scanf("%lld %lld", &n, &d);
        int flag = 0;
        if ( n >= d ) flag = 1;
        else
        {
            long long int dis;
            for ( long long int i = 1; i <= n; i ++ )
            {
                dis = ceil( d * 1.0 / (i + 1) );
                //printf("%d\n", i + dis);
                if ( i + dis <= n ) 
                {
                    flag = 1;
                    break;
                }
            }
        }
        if ( flag  ) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}

