#include <bits/stdc++.h>

using namespace std;

int T;
long long int n, p;


int main()
{
    scanf("%d",&T);
    while ( T-- )
    {
        scanf("%lld %lld",&p,&n);
        long long int ans = 1;
        for ( int i = 1; i <= n; i ++ )
        {
            ans *= (( p - 1 ) % p);
        }
        printf("%lld\n",ans);

    }
    
    return 0;
}
