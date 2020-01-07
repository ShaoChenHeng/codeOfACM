#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T,n,k;
ll a[110];

// k = 1
// 5 4 3

int main()
{
    scanf("%lld",&T);
    while ( T -- ) 
    {
        ll ans = 0x3f3f3f3f;
        scanf("%lld %lld",&n,&k);
        for ( int i = 0; i < n; i++ ) scanf("%lld",&a[i]);
        sort(a, a + n);
        if ( a[n - 1] - k - ( a[0] + k ) > 0 ) 
        {
            printf("-1\n");
        }
        else
        {
            for ( int i = 0; i < n; i ++ )
            {
                ans = min ( ans , a[i] + k );
            }
            printf("%lld\n",ans);
        }
        
    } 
    return 0;
}
