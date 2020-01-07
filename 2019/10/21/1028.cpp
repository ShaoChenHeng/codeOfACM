#include<stdio.h>

long long dp[121][121]={0};

int main()
{
	int n,i,j,k;
	for(i=1;i<121;i++)
	{
		for(j=1;j<121;j++)
		{
			if( i < j ) dp[i][j] = dp[i][i];
			else if(i>j) dp[i][j] = dp[i-j][j] + dp[i][j-1];
			else dp[i][j]= 1 + dp[i][j-1];
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",dp[n][n]);
	}
	return 0;
}
