#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll q,k,n,a,b;

int main()
{
    scanf("%lld",&q);
    while ( q -- )
    {
        scanf("%lld %lld %lld %lld",&k,&n,&a,&b);
        ll _max = k / b;
        if ( _max == n && _max * b == k ) printf("-1\n");
        else
        {
            ll  l = 0, r = _max;
            while ( l < r )
            {
                ll mid = l + ( r - l ) / 2;
                if ( mid * a >= k )
                {
                    r = mid;
                }
                if ( ceil((double)(k - mid * a - b) / b) + mid >= n )
                {
                    l = mid + 1;
                }
                else r = mid;
            }
            if ( ceil( ( k - l * a - b ) / b ) + l >= n )
            {
                printf("%lld\n",min( l, n ));
            }
            else printf("%lld\n",min( l - 1, n ));

        }
    }
    return 0;
}
