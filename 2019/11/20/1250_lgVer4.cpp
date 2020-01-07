#include <bits/stdc++.h>
#define INF 10000

using namespace std;
int V, E, d[300], cost[300][300];
bool used[300];

void dijsktra( int s )
{
    fill( d, d + V + 1, INF);
    fill( used, used + V  + 1, false );
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
    scanf("%d",&V);
    scanf("%d ", &E);
    int u,v,c;
    int S = V + 1;
    for ( int i = 0; i < 300; i++ ) for ( int j = 0; j < 300; j++ ) cost[i][j] = INF;
    cost[S][0] = 0;
    for ( int i = 1; i <= V; i ++ ) cost[i-1][i] = 1;
    for ( int i = 1; i <= V; i ++ ) cost[i][i-1] = 0;
    for ( int i = 1; i <= V; i ++ ) cost[S][i] = 0;


    for ( int i = 1; i <= E; i++ )
    {
        scanf("%d %d %d", &u, &v, &c);
        cost[v][u-1] = -c;
    }
    dijsktra(S);
    for ( int i = 0; i <= V; i++ ) printf("%d ",d[i]);
    printf("\n"); 
    //printf("%d\n", d[v+1]);
    return 0;
}
