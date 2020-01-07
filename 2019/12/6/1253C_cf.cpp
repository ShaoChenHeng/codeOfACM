#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n,m;
ll a[200010],dp[200010];

//dp[k] 前k个糖果的惩罚
//dp[k] = dp[k-1] + sum[k]

int main()
{
    memset(dp, 0, sizeof(dp));
    scanf("%lld %lld",&n,&m);
    for ( int i = 1; i <= n; i ++ ) scanf("%lld",&a[i]);
    sort(a + 1, a + n + 1);
    ll sum = 0;
    for ( int i = 1; i <= n; i ++ )
    {
        sum += a[i];
        dp[i] = sum;
        if ( i > m ) dp[i] += dp[i - m];
        printf("%lld ",dp[i]);
    }
    printf("\n");

    return 0;
}

