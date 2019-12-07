#include <bits/stdc++.h>

using namespace std;

int T;
long long int n;

int main()
{
    scanf("%d",&T);
    while( T -- )
    {
        scanf("%lld",&n);
        long long int ans = ( 1 + n ) * n;
        if ( n % 2 ) printf("%lld\n",ans);
        else printf("%lld\n",-ans);
    }
    return 0;
}
