#include <bits/stdc++.h>
#define INF 10000

using namespace std;
int _prev[10000];
int V, E, d[1000], cost[100][100];
bool used[1000];

void dijsktra( int s )
{
    fill( d, d + V, INF);
    fill( used, used + V, false );
    d[s] = 0;

    while ( true )
    {
        int v = -1;
        for ( int u = 0; u < V; u ++ )
        {
            if ( !used[u] && ( v == -1 || d[u] < d[v] ) ) v = u;
        }
        if ( v == -1 ) break;
        used[v] = true;

        for( int u = 0; u < V; u++ ) d[u] = min(d[v] + cost[v][u], d[u]);
    }

}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d %d",&V, &E);
    int u,v,c;
    for ( int i = 0; i < 100; i++ ) for ( int j = 0; j < 100; j++ ) cost[i][j] = INF;
    
    for ( int i = 0; i < E; i++ )
    {
        scanf("%d %d %d", &u, &v, &c);
        cost[u][v] = c;
        cost[v][u] = c;
    }
    dijsktra(0);
    for ( int i = 0; i < V; i++ ) printf("%d ",d[i]);
    printf("\n");
    printf("ans = %d", d[v]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
