//P1135_luogu
//1548hdu

#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int k[210], vis[210];
int step[210];
vector<int> g[2100];

int main()
{
    while( scanf("%d", &n) != EOF && n )
    {
        scanf("%d %d",&a, &b);
        memset(step, 0, sizeof(step));
        memset(vis, 0, sizeof(vis));
        for ( int i = 1; i <= n; i ++  ) scanf("%d",&k[i]);
        for ( int i = 0; i <= n; i ++ ) g[i].clear();
        for ( int i = 1; i <= n; i ++ )
        {
            if ( i + k[i] <= n ) g[i].push_back(i + k[i]);
            if ( i - k[i] > 0 ) g[i].push_back(i - k[i]);
        }
        queue<int> q;
        vis[a] = 1;
        q.push(a);
        int u;
        while ( !q.empty() )
        {
            u = q.front(); q.pop();
            //vis[u] = 0;
            if ( u == b ) break;
            int d = g[u].size();
            for ( int i = 0; i < d; i ++ )
            {
                int to = g[u][i];
                if ( !vis[to] ) 
                {
                    vis[to] = 1;
                    q.push(to);
                    step[to] = step[u] + 1;
                }
            } 
           /*  if ( u + k[u] <= n && u + k[u] >= 1 && !vis[u + k[u]] )
            {
                q.push(u + k[u]);
                step[u + k[u]] = step[u] + 1;
                vis[u + k[u]] = 1;
            }
            if ( u - k[u] >= 1 && u - k[u] <= n && !vis[u - k[u]] )
            {
                q.push(u - k[u]);
                step[u - k[u]] = step[u] + 1;
                vis[u - k[u]] = 1;
            } */
        }
        if ( u == b ) printf("%d\n",step[b]);
        else printf("-1\n");
    }
    
    return 0;
}
