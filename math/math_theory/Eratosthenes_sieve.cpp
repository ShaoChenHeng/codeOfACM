#include <bits/stdc++.h>

using namespace std;
const int N = 100000;

bool vis[N];
int n;

int sieve(int n)
{
    int m = sqrt(n + 0.5);
    memset( vis, 0, sizeof(vis) );
    for ( int i = 2; i <= m; i++ )
    {
        if ( !vis[i] )
        {
            for( int j = i * i; j <= n; j += i ) vis[j] = 1;
        }
    }
}

int main()
{
    scanf("%d",&n);
    sieve(n);
    for ( int i = 2; i < n; i++ )
    {
        if ( !vis[i] ) printf("%d ",i);
    }
    return 0;
}
