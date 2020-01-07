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
        if ( b * n >= k ) printf("-1\n");
        else printf("%lld\n",min(n, ( k - 1 - b * n ) / ( a - b )));
    }
    return 0;
}
