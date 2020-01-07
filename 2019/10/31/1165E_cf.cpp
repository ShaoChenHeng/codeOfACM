#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD (ll)998244353


ll a[2000010];
ll b[2000010];
int n;

/* 5
1 8 7 2 4
9 7 2 9 3
 */


int main()
{
    scanf("%d",&n);
    for ( int i = 0; i < n; i++ ) scanf("%lld",&a[i]);
    for ( int i = 0; i < n; i++ ) scanf("%lld",&b[i]);
    for ( int i = 0; i < n; i++ )
    {
        a[i] = a[i] * ( i + 1 ) * ( ll ) ( n - i );
    }
    sort(a, a + n);
    sort(b, b + n);
    ll ans = 0;
    for ( int i = 0; i < n; i++ ) 
    {
        ans = ( ans + a[i] % MOD * b[n - i -1 ] % MOD ) % MOD;
    }
    printf("%lld",ans);

    return 0;
}
