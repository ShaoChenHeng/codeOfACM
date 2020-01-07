#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int a[100];
int dp[100][5000];
char s[100][100];

int main()
{
    while ( scanf("%d",&T) != EOF)
    {
        int n;
        while ( T -- )
        {
            int o1,o2;
            o1 = 0,o2 = 0;
            scanf("%d",&n);
            for ( int i = 1; i <= n; i++ ) 
                scanf("%s",s[i] + 1), a[i] = strlen(s[i]+1);
            //scanf("%s",s[i] + 1)读入一行字符串
            //a[i] = strlen(s[i]+1)记录字符串长度
            
            for ( int i = 1; i <= n; i++ )         
            {
                for ( int j = 1; j <= a[i]; j ++ )
                {
                    if ( s[i][j] == '1' ) o1 ++;
                    if ( s[i][j] == '0' ) o2 ++;
                }
            }
            memset(dp,-1,sizeof(dp));
            dp[0][0] = 0;
            //ckMax( f[i][j+k], f[i-1][j]+((k&1)&&(a[i]&1))+(!(k&1)) );
            for ( int i = 1; i <= n; i++ )
            {
                for ( int j = 0; j <= o1; j++ )
                {
                    for ( int k = 0; k <= a[i] && k + j <= o1; k ++ )
                    {
                        if ( ~dp[i-1][j] ) dp[i][j+k] = max( dp[i][j+k], dp[i-1][j]+( ( k & 1 ) && ( a[i] & 1 ) ) + ( ! ( k & 1 ) ) );
                    }
                }
            }
            printf("%d\n",dp[n][o1]);
        }
    }
    

    return 0;
}
