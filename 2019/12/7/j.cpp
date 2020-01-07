#include <bits/stdc++.h>

using namespace std;

int T, n;

int main()
{
    scanf("%d",&T);
    while( T -- )
    {
        scanf("%d",&n);
        double ans = 1;
        for ( int i = 2 , j = 2; i <= n, j <= n; i ++, j ++ )
        {
            ans *= ( 1 + i );
            ans /= ( 1 - j );
        }
        ans *= 2;
        
        printf("%.0lf\n",ans);

    }
    return 0;
}
