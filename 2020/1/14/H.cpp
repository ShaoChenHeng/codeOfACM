#include <bits/stdc++.h>

using namespace std;

int n, m, k, _count = 0, totalone = 0;
int arr[110][110];
int dp[110];

int _swap( int line )
{
    int sum = 0, ans = -1, minchange;
    for ( int i = 1; i <= n; i ++ )
    {
        sum = 0;
        if ( arr[i][line] == 1 )
        {   
            totalone ++;
            for ( int j = i; j <= k + i - 1; j ++ )
            {
                if ( arr[j][line] == 1 ) sum ++;
            }
        }
        //ans = max( ans, sum );
        if ( sum > ans )
        {
            ans = sum;
            minchange = totalone - ans;
        }
    }
    printf("ans = %d minchange = %d",ans,minchange);
    return ans;
}

int uswap( int line )
{
    int sum = 0;
    for ( int i = 1; i <= n; i ++ )
    {
        sum = 0;
        if ( arr[i][line] == 1 )
        {
            for ( int j = i; j <= k + i - 1; j ++ )
            {
                if ( arr[j][line] == 1 ) sum ++;
                return sum;
            }
        }
    }
}
int main()
{
    scanf("%d %d %d",&n, &m, &k );
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= m; j ++ )
        {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= m; i ++  )
    {
        int sp = _swap(i);
        int usp = uswap(i);
        printf("sp=%d\n",sp);
        printf("usp=%d\n",usp);
        if ( sp > usp )
        {
            dp[i] = dp[i-1] + sp;
            _count += ( totalone - sp );
        }
        else dp[i] = dp[i-1] + usp;
        totalone = 0;
    }
    printf("%d %d\n",dp[m], _count);
    return 0;
}
/*
7 3 4
0 1 1
1 0 0
0 1 1
1 1 0
0 1 1
1 1 1
1 1 1
*/
