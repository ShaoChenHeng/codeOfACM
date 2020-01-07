#include <bits/stdc++.h>

using namespace std;

int n,c;
int a[200010],b[200010];
int dp[200010][2];

//dp[i][0/1]: 当前上了i层，用电梯/楼梯所用的最短时间
//dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1]
//dp[i][1] = min(dp[i-1][0] + c, dp[i-1][1]) + b[i-1]

int main()
{
	scanf("%d %d",&n,&c);
	for ( int i = 1; i < n; i++ )
    {
        scanf("%d",&a[i]);
    }
    for ( int i = 1; i < n; i++ )
    {
        scanf("%d",&b[i]);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1][0] = 0;
    //dp[1][1] = 0;
    //printf("dp11 = %d\n",dp[1][1] );
    printf("0 ");
    for ( int i = 2; i <= n; i++ )
    {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1];
        dp[i][1] = min(dp[i-1][0] + c, dp[i-1][1]) + b[i-1];
        printf("%d ",min(dp[i][0], dp[i][1]));
    }
    printf("\n");
    //printf("dp11 = %d\n",dp[1][1] );
    return 0;
}
