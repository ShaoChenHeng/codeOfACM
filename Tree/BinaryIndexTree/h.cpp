#include<bits/stdc++.h>

using namespace std;

long long int a[1000100];
long long int C[8000100];
int n;

long long int lowbit(  long long int x ) { return x & (-x); }

long long int sum( long long int x )
{
    long long int ret = 0;
    while ( x > 0 )
    {
        ret += C[x];
        x -= lowbit( x );
    }
    return ret;
}

void add(  long long int x,  long long int d)
{
    while ( x <= n )
    {
        C[x] += d;
        x += lowbit(x);
    }
}

int main()
{
    long long int k;
    long long int ans = 0;
    scanf("%d %lld",&n, &k);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%lld",&a[i]);
        add( i,a[i] );
    }
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = i; j <= n; j ++ )
        {
            if ( sum(j) - sum(i - 1) <= k ) ans ++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
