#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1010];
int value[1010];

bool cmp(int a, int b) { return a > b; }

int main()
{
    int n,m;
    while(scanf("%d",&n) != EOF && n)
    {
        memset(dp,0,sizeof(dp));
        for ( int i = 0; i < n; i++ ) scanf("%d",&value[i]);
        scanf("%d",&m);
        sort( value,value+n);
        
        int maxV = value[n-1];
        if ( m < 5 ) {printf("%d",m);continue;}
        m -= 5;
        for( int i = 0; i < n; i ++ )
        {
            for ( int j = m; i >= value[i]; j -- )
            {
                dp[j] = max( dp[j], dp[j - value[i]] + value[i] );
            }
        }
        printf("%d\n",m + 5 - dp[m] - maxV);
    }
    return 0;
}
