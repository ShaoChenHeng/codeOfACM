#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,T;
ll a[10000010];

int main()
{
    scanf("%d",&T);
    while( T -- )
    {
        scanf("%d",&n);
        for ( int i = 0; i < n; i++ )
        {
            scanf("%lld",&a[i]);
        }
        sort( a,a+n );
        ll ans = a[0] * a[n-1];
        ll q = sqrt(ans);
        int cur = 0;
        for ( int i = 2; i <= q; i++ )
        {
            if ( ans % i == 0 )
            {
                if ( a[cur] != i || a[cur] * a[n-cur-1] != ans )
                {
                    ans = -1;
                    break;
                }
                ++ cur;
            }
        }
        q = ( n + 1 ) / 2;
        for ( int i = cur; i < q; i++ )
        {
            if ( a[i] * a[n-i-1] != ans)
            {
                ans = -1; break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
