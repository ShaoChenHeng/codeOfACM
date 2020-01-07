#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int dp[4][100010];
//int dp[100010];
int value[3] = {150, 200, 350};
int T;
int max (int a,int b)
{
	return (a>b)?a:b;
}

int main()
{
    cin >> T;
    while( T -- )
    {
        int m;
        cin >> m;
        memset(dp,0,sizeof(dp));
        for ( int i = 0; i < 3;i++ )
        {
            for(int j = value[i];j <= m; j++) 
            {
                if ( j < value[i] ) dp[i + 1][j] = dp[i][j];
                else dp[i+1][j] = max( dp[i][j], dp[i+1][j-value[i]] + value[i] );
            }
            //dp[j] = max(dp[j],dp[j-value[i]]+value[i]);
        }
        printf("%d\n",m - dp[2][m]);
    }
    return 0;
}


/* #include<iostream>
#include<cstring>
using namespace std;
int dp[10010];
int c[3] = {150,200,350};
int max (int a,int b)
{
	return (a>b)?a:b;
}
int main ()
{
	int n;
	cin >> n;
	while(n--)
	{
		int V;
		cin >> V;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < 3;i++)
		{
			for(int j = c[i];j <= V;j++)
			dp[j] = max(dp[j],dp[j-c[i]]+c[i]);
		}
		cout << V-dp[V] << endl;
	}
	return 0;
} */
