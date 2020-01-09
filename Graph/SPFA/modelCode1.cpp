#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

struct edge
{
    int to, next, w;
} s[1000];

int D, P, C, F, di;
bool vis[1000];
int d[1000], head[1000], num = 0, in[1000];
queue<int> q;

void build ( int u, int v, int w )
{
    s[++num].to = v;
    s[num].w = w;
    s[num].next = head[u];
    head[u] = num;
}

int spfa( int x )
{
    memset(d, 1e9, sizeof(d));
    q.push(x);
    d[x] = 0;
    vis[x] = 1;

    while ( !q.empty() )
    {
        int u = q.front(); q.pop();
        vis[u] = false;
        in[u] ++;
        if ( in[u] > C + 1) return 1;
        for ( int i = head[u]; i; i = s[i].next )
        {
            int v = s[i].to;
            if ( d[u] + s[i].w < d[v] )
            {
                d[v] = d[u] + s[i].w;
                if ( !vis[v] ) vis[v] = true, q.push(v);
            }
        }

    }
    return 0;
}

int main()
{
    scanf("%d %d %d %d", &di, &P, &C, &F);
    for ( int i = 0; i < P; i ++ )
    {
        int u, v;
        scanf("%d %d",&u,&v);
        build( u, v, -di );
    }
    for ( int i = 0; i < F; i ++ )
    {
        int u, v, w;
        scanf("%d %d %d",&u, &v, &w);
        build( u, v, w - di );
    }
    for ( int i = 1; i <= C; i ++  ) build( 0, i, -di);
    if ( spfa(0) ) printf("orz\n");
    else
    {
        int ans = 0;
        for ( int i = 1; i <= C; i ++ )
        {
           ans = min( ans, d[i] );
        }
        printf("%d\n", -ans);
    } 
    /* for ( int i = 1; i <= C; i ++ )
    {
        printf("%d ",d[i]);
    }
    printf("\n");  */
    return 0;
}
