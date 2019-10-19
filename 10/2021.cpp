#include <cstdio>
#define INF 10000

using namespace std;


int n;
int a[110];
int dp[20000];
int v[] = { 100, 50, 10, 5, 2, 1, };

//f(i) = min{ INF, f(i - v[j]) + 1 | v[j] <= i }
//面值恰好为i时，硬币最小数

int min(int n, int m)
{
    if ( n > m ) return m;
    return n;
}

int dfs( int n )
{
    if ( n == 0 ) return 0;
    for ( int i = 0; i <= 5; i++ )
    {
        if ( v[i] <= n  ) 
        {
            dp[n] = min( INF, dfs(n - v[i])) + 1;
            break;
        }
    }
    return dp[n];
}


int main()
{
    dp[1] = 1;
    while(scanf("%d",&n) != EOF && n)
    {
        int sum = 0;
        for ( int i = 0; i < n; i ++ ) scanf("%d",&a[i]);
        for ( int i = 0; i < n; i++ ) sum += dfs(a[i]);
        //printf("%d\n",dfs(a[i]));
        printf("%d\n",sum);
    }
    return 0;
}
