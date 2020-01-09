//1596_hdu
#include <bits/stdc++.h>

using namespace std;

int n, q;
double graph[1010][1010];
double d[1010][1010];

int main()
{
    while ( scanf("%d",&n) != EOF && n )
    {
        memset( graph, 0, sizeof(graph) );
        for ( int i = 1; i <= n; i++ ) 
        {
            for ( int j = 1; j <= n; j ++ )
            {
                scanf("%lf",&graph[i][j]);
            }
        }
        
        memcpy(d, graph, sizeof(graph));
        for ( int k = 1; k <= n; k ++ )
        {
            for ( int i = 1; i <= n; i ++ )
            {
                for ( int j = 1; j <= n; j ++ )
                {
                    d[i][j] = max( d[i][j], d[i][k] * d[k][j]);
                }
            }
        }
        scanf("%d",&q);
        while ( q -- )
        {
            int from, to;
            scanf("%d %d",&from, &to);
            if ( d[from][to] == 0 ) printf("What a pity!\n");
            else printf("%.3lf\n",d[from][to]);
        }
    }
    return 0;
}
