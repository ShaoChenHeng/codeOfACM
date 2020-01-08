#include <bits/stdc++.h>

using namespace std;

int n,K;
int num[50];
char ss[50];

struct node 
{
    int len;
    int ans[100];
} dp[10][50];

node cal( node item, int beg, int end )
{
    node anser, y;
    memset( anser.ans, 0, sizeof(anser.ans) );
    memset( y.ans, 0, sizeof(y.ans) );
    y.len = end - beg + 1;
    for ( int i = end; i >= beg; i -- ) y.ans[end-i+1] = num[i];
    int l1 = item.len, l2 = y.len, ll;
    for ( int i = 1; i <= l1; i ++ )
    {
        for ( int j = 1; j <= l2; j ++ )
        {
            anser.ans[i+j-1] += item.ans[i] * y.ans[j];
        }
    }
    ll = l1 + l2 - 1;
    for ( int i = 1; i <= ll; i ++ )
    {   
        anser.ans[i+1] += anser.ans[i] / 10;
        anser.ans[i] = anser.ans[i] % 10;
    }
    if ( anser.ans[ll+1] ) ll ++;
    anser.len = ll;
    return anser;
}

node cmp( node a, node b )
{
    if ( a.len > b.len ) return a;
    else if ( a.len < b.len ) return b;
    for ( int i = a.len; i >= 1; i -- )
    {
        if ( a.ans[i] > b.ans[i] ) return a;
        else if ( a.ans[i] < b.ans[i] ) return b;
    }
    return a;
}

int main()
{
    scanf("%d %d",&n, &K);
    scanf("%s",ss);
    for ( int i = 1; i <= n; i ++ ) num[i] = ss[i-1] - '0';

    for ( int i = 1; i <= n; i ++ )    
    {   
        for ( int j = i; j >= 1; j -- ) dp[0][i].ans[++dp[0][i].len] = num[j];
    }

    for ( int i = 2; i <= n; i ++ )
    {
        for ( int k = 1; k <= min( K, i - 1 ); k ++ )
        {
            for ( int j = k; j < i; j ++ )
            {
                dp[k][i] = cmp( dp[k][i], cal( dp[k-1][j], j + 1, i ) );
            }
        }
    }
    for ( int i = dp[K][n].len; i >= 1; i -- )
    {
        printf("%d",dp[K][n].ans[i]);
    }
    printf("\n");

    return 0;
}
