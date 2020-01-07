#include <bits/stdc++.h>
#define N 30010
#define INF 10020000
using namespace std;

int n, m;
int to[N], net[N], w[N], dis[N], h[N], cnt;
bool vis[N];
queue<int> q;

void add( int u , int v, int c )
{
    to[++cnt] = v;
    net[cnt] = h[u], h[u] = cnt;
    w[cnt] = c;
}

int main()
{
    scanf("%d %d", &n, &m);
    int u,v,c;
    while ( m --)
    {
        scanf("%d %d %d", &u, & v, &c);
        add( u - 1, v, c );
    }   
    printf("to   net   w   h\n");
    for ( int i = 0; i < 10; i++ )
    {
        printf( "%d %d %d %d\n",to[i], net[i], w[i], h[i] );
    } 
    for ( int i = 0; i < n; i++ )
    {
        if ( i != 0 ) add( i - 1, i, 0 ), dis[i] = -INF;
        if ( i != n ) add( i, i - 1, -1 );
    }
    q.push(0);
    while ( !q.empty() )
    {
        int u = q.front();
        vis[u] = 0;
        q.pop();
        for ( int i = h[u]; i ; i = net[i] )
        {
            if ( dis[to[i]] < dis[u] + w[i] )
            {
                dis[to[i]] = dis[u] + w[i];
                if ( !vis[to[i]] ) 
                {
                    q.push( to[i] );
                    vis[to[i]] = 1;
                }
            }
        }
    }
    printf("to   net   w   h\n");
    for ( int i = 0; i < n; i++ )
    {
        printf( "%d %d %d %d\n",to[i], net[i], w[i], h[i] );
    }
    cout << dis[n];
    return 0;
}
