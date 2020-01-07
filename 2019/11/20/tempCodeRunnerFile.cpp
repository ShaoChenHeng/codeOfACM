#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
struct edge
{
    int from, to, cost;
} es[30010];
int cnt = 0;
int V, E, d[30010];


void shortest_path(int s)
{
    for (int i = 0; i < V; i++  ) d[i] = INF;
    d[s] = 0;
    while ( true )
    {
        bool update = 0;
        for ( int i = 0; i < cnt; i ++ )
        {
            edge e = es[i];
            if ( d[e.from] != INF && d[e.to] > d[e.from] + e.cost )
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if ( !update ) break;
    }
}

void build( int u, int v, int cost )
{
    es[cnt].from = u;
    es[cnt].to = v;
    es[cnt].cost = cost;
    cnt ++;
}

int main()
{
    scanf("%d",&V);
    scanf("%d", &E);
    int u,v,c;
    int S = V + 1;
    build( S, 0, 0 );
    for ( int i = 1; i <= V; i ++ ) 
    {
        build( S, i, 0 );
        build( i, i - 1, 0 );
        build( i - 1, i, 1 );

    }

    for ( int i = 1; i <= E; i++ )
    {
        scanf("%d %d %d", &u, &v, &c);
        build( v, u - 1, -c );
    }
    shortest_path(0);
    int mind = 0x3f3f3f3f;
    for ( int i = 0; i <= V; i++ ) mind = min( mind, d[i] );
    printf("%d\n", d[V] - mind);
    return 0;
}
