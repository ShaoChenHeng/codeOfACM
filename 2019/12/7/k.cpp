#include <bits/stdc++.h>

using namespace std;

int q;

int main()
{
    long long int n;
    scanf("%d",&q);
    while ( q -- )
    {
        scanf("%lld",&n);
        double ans = (sqrt( 1 + 4 * ( n - 1 ) / 3 ) - 1)/ 2;
        long long int ans2 = (sqrt( 1 + 4 * ( n - 1 ) / 3 ) - 1)/ 2;

        if ( ans - ans2 > 0.000001 ) printf("NO\n");
        else 
        {
            if ( ans2 < 1 ) printf("NO\n");
            else printf("YES\n");

        }
        
    }
    return 0;
}
