#include <bits/stdc++.h>
using namespace std;
const int MOD =  1e9 + 7;

long long int n, m;

int main()
{
    scanf("%lld %lld", &n, &m);
    long long int part = 0;
    long long int left = n - 2;
    if ( left > 0 )
    {
        part += (left * n * 2 ) % MOD;
        if ( m - 2 > 0 ) part += ( ( left * 2 * n  % MOD) * (m - 2) ) % MOD;
    }
    long long int up = m - 2;
    if ( up > 0 ) 
    {
        part += ( up * m * 2 ) % MOD;
        if ( n - 2 > 0 ) part += ( ( up * 2 * m  % MOD) * ( n - 2) ) % MOD;
    }
    if ( m - 1 > 0 && n - 2 > 0 && m - 2 > 0 ) part += ( ( m - 1 ) * ( n - 2 ) % MOD) * ( m - 2 ) * 2 % MOD;
    if ( n - 1 > 0 && m - 2 > 0 && n - 2 > 0 ) part += ( ( n - 1 ) * ( m - 2 ) % MOD) * ( n - 2 ) * 2 % MOD;
    printf("%lld\n",part % MOD);
    return 0;
}
