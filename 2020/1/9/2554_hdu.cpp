#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

struct edge
{
    int to, next, w;
} s[10010];

int n, m;
bool vis[10010];
int head[10010], d[10010], num;
queue<int> q;

void build( int from, int to, int w )
{
    s[++num].w = w;
    s[num].next = head[from];
    head[from] = num;
    s[num].to = to;
}

void spfa( int x )
{
    while (!q.empty()) q.pop();
    q.push(x);
    memset(vis, 0, sizeof(vis));
    for ( int i = 0; i <= n; i ++ ) d[i] = INF;
    d[x] = 0;
    vis[x] = 1;
    while ( !q.empty() )
    {
        int u = q.front(); q.pop();
        vis[u] = false;
        for ( int i = head[u]; i; i = s[i].next )
        {
            int v = s[i].to;
            if ( d[u] + s[i].w < d[v] )
            {
                d[v] = d[u] + s[i].w;
                if ( !vis[v] ) vis[v] = true; q.push(v);
            }
        }
    }
}

int main()
{
    while ( scanf("%d %d", &n, &m) == 2 && n )
    {
        int from, to, cost;
        num = 0;
        memset(head, 0, sizeof(head));
        for ( int i = 0; i <= n; i ++ )
        {
            s[i].to = 0;
            s[i].next = 0;
            s[i].w = 0;
        }
        for ( int i = 0; i < m; i ++ )
        {
            scanf("%d %d %d",&from, &to, &cost);
            build( from, to, cost);
            build( to, from, cost);
        }
        spfa(1);
        printf("%d\n",d[n]);
    }
    return 0;
}
