#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

int n, k, _max = 0;
int dp[10000], ans[100], f[100];

void dfs( int x )
{
    if ( x == k + 1 )
    {
        memset(dp, 0, sizeof(dp));
        int i = 0;
        while ( dp[i] <= n )
        {
            i ++;
            dp[i] = INF;
            for( int j = 1; j <= k && 0 <= i - f[j]; j ++ ) 
            {
                dp[i] = min( dp[i], dp[i-f[j]] + 1 );
            }
        }
        if ( i - 1 > _max ) 
        {
            _max = i - 1;
            for ( int j = 1; j <= k; j ++ ) ans[j] = f[j];
        }
        return ;
    }
    for ( int j = f[x-1] + 1; j <= f[x-1] * n + 1; j ++ )
    {
        f[x] = j;
        dfs( x + 1 );
    }

}

int main()
{
    scanf("%d %d", &n, &k);
    f[1] = 1;
    dfs(2);
    for ( int i = 1; i <= k; i ++ ) printf("%d ", ans[i]);
    printf("\n");
    printf("MAX=%d\n", _max);
    return 0;
}
