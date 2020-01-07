#include<iostream>
#include<algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int c;
int deep;
int a[101][101];
int dp[101][101];

//dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
//dp[i][j]+=a[i][j]

int main()
{
    while(scanf("%d",&c) != EOF)
    {
        while( c-- )
        {
            memset(dp,0,sizeof(dp));
            scanf("%d",&deep);
            for(int i = 1; i <= deep; i++)
                for(int j = 1; j <= i; j++)
                    scanf("%d",&a[i][j]);
            for(int i = 1; i <= deep;i ++) dp[deep][i] = a[deep][i];
            for(int i = deep - 1; i >= 0; i --)
                for(int j = 1; j <= i; j ++)
                {
                    dp[i][j] = max( dp[i+1][j], dp[i+1][j+1] );
                    dp[i][j] += a[i][j];
                }
            printf("%d\n",dp[1][1] );
        }

    }
    return 0;
}

