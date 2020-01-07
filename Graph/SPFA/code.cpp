#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

struct edge
{
    int to, next, w;
} s[1000];

int v,e;
bool vis[1000];
int d[1000], head[1000], num;
queue<int>q;

void build( int u, int v, int w )
{
    s[++num].w = w;
    s[num].next = head[u];
    head[u] = num;
    s[num].to = v;
}

void spfa(int x)
{
    q.push(x);
    for ( int i = 0; i < v; i++ ) d[i] = INF;
    d[x] = 0;
    vis[x] = 1;
    while( !q.empty() )
    {
        int u=q.front(); q.pop();
        vis[u] = false;
        for( int i = head[u]; i; i = s[i].next )
        {
            int v = s[i].to;
            if( d[u] + s[i].w < d[v] )
            {
                d[v] = d[u] + s[i].w;
                if( !vis[v] ) vis[v] = true, q.push(v);
            }
        }
    }

}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d %d", &v, &e);
    int u,v,w;
    for ( int i = 0; i < e; i++ )
    {   
        scanf("%d %d %d",&u, &v, &w);
        build(u, v, w);
    }
    spfa(0);
    for ( int i = 0; i < v + 1; i ++ ) printf("%d ",d[i]);
    printf("\n");
    printf("ans = %d",d[v]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
