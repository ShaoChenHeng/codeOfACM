#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,x;
ll a[300010],mx;
ll dp[300010][3];
string ss;

//dp[i][3]
//dp[i][0] := 以a[i]为结尾不考虑x时的最大值，
//dp[i][1] := 以a[i] * x 为结尾的最大值
//dp[i][2] := 以a[i]结尾且考虑x时的最大值

//dp[i][0] = max( dp[i-1][0] + a[i], a[i] )
//dp[i][1] = max( max( dp[i-1][0], dp[i-1][1] ) + a[i] *x, a[i] * x )
//dp[i][2] = max( max( dp[i-1][0], dp[i-1][1], dp[i-1][2] ) + a[i],a[i] )

int main()
{
    scanf("%d %d",&n,&x);
    for ( int i = 0; i < n; i++ )
    {
        scanf("%lld",&a[i]);
    }
    //mx = -10000000;
    for( int i = 0; i < n; i++ )
    {
        dp[i][0] = max( dp[i-1][0] + a[i], a[i] );
        dp[i][1] = max( max( dp[i-1][0], dp[i-1][1] ) + a[i] *x, a[i] * x );
        dp[i][2] = max( max ( max( dp[i-1][0], dp[i-1][1]) , dp[i-1][2] ) + a[i], a[i] );
        mx = max( max(mx,dp[i][0]) , max( dp[i][1], dp[i][2] ) );
    }
    /* for ( int i = 0; i < n; i++ )
    {
        printf("0 = %lld 1 = %lld 2 = %lld\n",dp[i][0],dp[i][1],dp[i][2]);
    } */ 
    printf("%lld\n",mx);
    return 0;
}
