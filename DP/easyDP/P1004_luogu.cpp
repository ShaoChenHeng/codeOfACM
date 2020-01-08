#include <bits/stdc++.h>

using namespace std;

int n;
int a[10][10];
int dp[10][10][10][10];

int main()
{
    scanf("%d",&n);
    int pos_x, pos_y, val;
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= n;j ++ ) a[i][j] = 0;
    }
    while ( scanf("%d %d %d", &pos_x, &pos_y, &val) == 3 && pos_x  ) 
    {
        a[pos_x][pos_y] = val;
    }
    for ( int i = 0; i <= 1; i ++ )
    {
        for ( int j = 0; j <= 1; j ++ )
        {
            for ( int k = 0; k <= 0; k ++)
            {
                for ( int l = 0; l <= 1; l ++ ) dp[i][j][k][l] = 0;
            }
        }
    }
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= n; j ++ )
        {
            for ( int x = 1; x <= n; x ++ )
            {
                /* int y = i + j - x;
                if ( y <= 0 ) break; */
                for ( int y = 1; y <= n; y ++ )
                {
                    dp[i][j][x][y] = 
                    max( max(dp[i-1][j][x-1][y],max( dp[i-1][j][x][y-1],dp[i][j-1][x-1][y])),dp[i][j-1][x][y-1]);
                    if ( i == x && j == y ) dp[i][j][x][y] += a[i][j];
                    else dp[i][j][x][y] += ( a[i][j] + a[x][y] );
                }
            }
        }
    }
    printf("%d\n", dp[n][n][n][n]);
    return 0;
}
