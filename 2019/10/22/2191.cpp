#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[10010];

int value[110];
int weight[110];
int cnt[110];

/* for(int i=0;i<m;i++)
    for(int j=1;j<=c[i];j++)
        for(int k=n;k>=p[i];k--)
            dp[k]=max(dp[k],dp[k-p[i]]+h[i]);
             */

int main ()
{
	int n,m,c;
	cin >> c;
	while( c-- )
	{
        scanf("%d %d",&n,&m);
		for ( int i = 0; i < m; i ++ ) scanf("%d %d %d",&value[i],&weight[i],&cnt[i]);
        
        memset(dp,0,sizeof(dp));

        for ( int i = 0; i < m; i++ )
        {
            for ( int j = 1; j <= cnt[i]; j++ )
            {
                for( int k = n; k >= value[i]; k -- )
                {
                    dp[k] = max( dp[k], dp[k - value[i]] + weight[i] );
                }
            }
        }
        printf("%d\n",dp[n]);
	}
	return 0;
}
