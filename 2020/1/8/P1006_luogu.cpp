#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[51][51];
int dp[51][51][51][51];

int main()
{
    scanf("%d %d",&n, &m);
    int pos_x, pos_y, val;
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= m;j ++ ) scanf("%d",&a[i][j]);
    }
    
    for ( int i = 0; i <= 1; i ++ )
    {
        for ( int j = 0; j <= 1; j ++ )
        {
            for ( int k = 0; k <= 1; k ++)
            {
                for ( int l = 0; l <= 1; l ++ ) dp[i][j][k][l] = 0;
            }
        }
    }
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= m; j ++ )
        {
            for ( int x = 1; x <= n; x ++ )
            {
                for ( int y = 1; y <= m; y ++ )
                {
                    dp[i][j][x][y] = 
                    max( max(dp[i-1][j][x-1][y],max( dp[i-1][j][x][y-1],dp[i][j-1][x-1][y])),dp[i][j-1][x][y-1]);
                    if ( i == x && j == y ) dp[i][j][x][y] += a[i][j];
                    else dp[i][j][x][y] += ( a[i][j] + a[x][y] );
                }
            }
        }
    }
    printf("%d\n", dp[n][m][n][m]);
    return 0;
}
