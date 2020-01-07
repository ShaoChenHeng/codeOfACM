#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;


int n, m, G[105][105];
bool vis[105][105], use[105][105];

int main()
{
    int q,cnt = 0;
    scanf("%d", &q);
    while ( q -- )
    {
        cnt ++;
        scanf("%d %d",&n, &m);
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
            {
                if ( i == j ) G[i][j] = 0;
                else G[i][j] = INF;
            }
        }
        int ans = 0;
        memset( use, 0, sizeof(use) );
        for ( int i = 1; i <= m; i++ )
        {
            int u, v, w;
            scanf("%d %d %d",&u, &v, &w);
            G[u][v] = G[v][u] = min( G[u][v], w );
            if ( use[u][v] ) ans ++;
            use[u][v] = use[v][u] = 1;
        }
        memset( vis, 0, sizeof(vis) );
        for ( int k = 1; k <= n; k ++ )
        {
            for ( int i = 1; i <= n; i ++ )
            {
                for ( int j = 1; j <= m; j++ )
                {
                    if ( G[i][j] >= G[i][k] + G[k][j] && i != k && k != j )
                    {
                        G[i][j] = G[i][k] + G[k][j];
                        if ( use[i][j] && !vis[i][j] )
                        {
                            vis[i][j] = vis[j][i] = 1;
                            ans ++;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d",cnt,ans);
    }

    return 0;
}
