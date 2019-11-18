#include <bits/stdc++.h>
#define INF 100000
using namespace std;

struct edge { int from, to, cost; };
edge es[10000];
int d[1000];
int V,E;

void shortest_path(int s)
{
    for (int i = 0; i < V; i++  ) d[i] = INF;
    d[s] = 0;
    while ( true )
    {
        bool update = 0;
        for ( int i = 0; i < E; i ++ )
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

bool find_negative_loop()
{
    memset( d, 0, sizeof(d) );

    for ( int i = 0; i < V; i++ )
    {
        for ( int j = 0; j < E; j++ )
        {
            edge e = es[j];
            if ( d[e.to] > d[e.from] + e.cost )
            {
                d[e.to] = d[e.from] + e.cost;
                if ( i == V - 1 ) return true;
            }
        }
    }
    return false;
}


int main()
{
    freopen("in.txt", "r",stdin);
    freopen("out.txt", "w", stdout );
    scanf("%d %d",&V, &E);
    for ( int i = 0; i < E; i++ ) scanf("%d %d %d",&es[i].from, &es[i].to, &es[i].cost);
    shortest_path(0);
    for( int i = 0; i < V; i++ ) printf("v = %d min = %d\n",i,d[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
