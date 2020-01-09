//3790_hdu
#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

struct edge
{
    int to, next, w, val;
} s[100010];

struct way
{
    int _long, value;
} d[10010];


int vis[10010];
int n, m;
int head[10010], num;
queue<int> q;

void build( int u, int v, int w, int val )
{
    s[++num].w = w;
    s[num].val = val;
    s[num].next = head[u];
    head[u] = num;
    s[num].to = v;
}

void spfa(int x)
{
    while (!q.empty()) q.pop();
    q.push(x);
    for ( int i = 1; i <= n; i ++ )
    {
        d[i].value = INF;
        d[i]._long = INF;
    }
    d[x].value = 0;
    d[x]._long = 0;
    vis[x] = 1;
    while ( !q.empty() )
    {
        int u = q.front(); q.pop();
        vis[u] = false;
        for ( int i = head[u]; i; i = s[i].next )
        {
            int v = s[i].to;
            if ( d[u]._long + s[i].w < d[v]._long )
            {
                d[v]._long = d[u]._long + s[i].w;
                d[v].value = d[u].value + s[i].val;
                if ( !vis[v] ) vis[v] = true; q.push(v);
            }
            else if ( d[u]._long + s[i].w == d[v]._long )
            {
                if ( d[u].value + s[i].val < d[v].value )
                {
                    d[v]._long = d[u]._long + s[i].w;
                    d[v].value = d[u].value + s[i].val;
                    if ( !vis[v] ) vis[v] = true; q.push(v);
                }   
            }
        }
    }
}



int main()
{
    while ( scanf("%d %d", &n, &m) == 2 && n ) 
    {
        num = 0;
        for ( int i = 0; i <= n; i ++ )
        {
            s[i].to = 0;
            s[i].next = 0;
            s[i].w = 0;
            s[i].val = 0;
        }
        memset(vis, 0, sizeof(vis));
        memset( head, 0, sizeof(head) );
        
        int from, to, w, val, beg, end;
        for ( int i = 0; i < m; i ++ )
        {
            scanf("%d %d %d %d", &from, &to, &w, &val);
            build( from, to, w, val );
            build( to, from, w, val );
        }
        scanf("%d %d",&beg, &end);
        spfa(beg);
        /* for ( int i = 1; i <= n; i ++ )
        {
            printf("%d %d\n",d[n]._long, d[n].value);
        } */
        printf("%d %d\n",d[end]._long, d[end].value);
    }
    return 0;
}
