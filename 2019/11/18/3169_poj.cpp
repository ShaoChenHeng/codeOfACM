#include <bits/stdc++.h>
#define INF 100100000
using namespace std;

int n, ML, MD;
int AL[1000010], BL[1000010], DL[1000010];
int AD[1000010], BD[1000010], DD[1000010];
int  d[1000010];
bool updated;

void update(int& x, int y)
{
    if ( x > y )
    {
        x = y;
        updated = true;
    }
}

void bellmanford()
{
    for ( int k = 0; k <= n; k ++ )
    {
        updated = false;
        for ( int i = 0; i + 1 < n; i ++ ) if ( d[i+1] < INF ) update( d[i], d[i+1] );
        for ( int i = 0; i < ML; i++ ) if ( d[AL[i] - 1] < INF ) update( d[BL[i] - 1], d[AL[i] - 1] + DL[i] ); 
        for ( int i = 0; i < MD; i++ ) if ( d[AD[i] - 1] < INF ) update( d[AD[i] - 1], d[BD[i] - 1] - DD[i] );
    }

}

void solve()
{
    fill( d, d + n, 0 );
    bellmanford();
    if ( updated ) { printf("-1"); return; }
    
    fill( d, d + n, INF );
    d[0] = 0;
    bellmanford();
    int res = d[n - 1];
    if ( res == INF ) res = -2;
    printf("%d\n", res);
}


int main()
{
    scanf("%d %d %d",&n, &ML, &MD);
    for ( int i = 0; i < ML; i ++ ) scanf("%d %d %d", &AL[i], &BL[i], &DL[i]);
    for ( int i = 0; i < MD; i ++ ) scanf("%d %d %d", &AD[i], &BD[i], &DD[i]);
    solve();
    return 0;
}
