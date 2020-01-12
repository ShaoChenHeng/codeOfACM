//P1364_luogu
//center tree
#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int next, to;
} e[10010];

int head[10010], w[10010], size[10010];
int num, n;
long long int ans = 2147483647, f[10010];

void build( int from, int to )
{
    e[++num].to = to;
    e[num].next = head[from];
    head[from] = num;
}

void dfs( int u, int fa, int dep )
{
    size[u] = w[u];
    for ( int i = head[u]; i; i = e[i].next )
    {
        if ( e[i].to != fa )
        {
            dfs(e[i].to, u, dep + 1);
            size[u] += size[e[i].to];
        }
    }
    f[1] += w[u] * dep;

}

void dp( int u, int fa )
{
    for ( int i = head[u]; i; i = e[i].next )
    {
        if ( e[i].to != fa )
        {
            f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2;
            dp( e[i].to, u );
        }
    }
    ans = min( ans, f[u] );
}

int main()
{
    ans *= ans;
    scanf("%d", &n);
    int a, b;
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d", &w[i]);
        scanf("%d %d",&a, &b);
        if ( a ) build(i, a), build(a, i);
        if ( b ) build(i, b), build(b, i);
    }
    dfs( 1, 0, 0 );
    dp(1, 0);
    printf("%lld\n", ans);


    return 0;
}
