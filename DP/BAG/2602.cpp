#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1010];
int value[1010];
int w[1010];

int main()
{
    int n,T,v;
    while(scanf("%d",&T) != EOF)
    {
        while( T -- )
        {
            scanf("%d %d",&n,&v);
            for ( int i = 0; i < n; i++ ) {scanf("%d",&value[i]);}
            for ( int i = 0; i < n; i++ ) scanf("%d",&w[i]);
            memset(dp,0,sizeof(dp));
            for ( int i = 0; i < n; i++ )
            {
                for ( int j = v; j >= w[i]; j --  )
                {
                    dp[j] = max( dp[j],dp[j-w[i]] + value[i] );
                }
            }
            printf("%d\n",dp[v]);
        }
    }
    return 0;
}
