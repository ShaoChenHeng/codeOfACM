#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iterator>

using namespace std;
const int maxn = 200010;

vector<int> G[maxn];
stack<int> S;
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt,dep[maxn];
int T;
int deepth;

void dfs( int u )
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for ( int i = 0; i < G[u].size(); i++ )
    {
        int v = G[u][i];
        if ( ! pre[v] )
        {
            deepth ++;
            dfs(v);
            lowlink[u] = min( lowlink[u], lowlink[v] );
        }
        else if ( !sccno[v] )
        {
            lowlink[u] = min( lowlink[u], pre[v] );
        }
    }
    dep[u] = deepth;
    if ( lowlink[u] == pre[u] )
    {
        scc_cnt ++;
        for ( ;; )
        {
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if ( x == u ) break;
        }
    }
}

void find_scc( int n )
{
    dfs_clock = scc_cnt = 0;
    memset( sccno, 0, sizeof(sccno) );
    memset( pre, 0, sizeof(pre) );
    for ( int i = 1; i <= n; i ++ )
    {
        if ( !pre[i] ) {deepth = 1;dfs(i);}
    }
}

int main()
{
    scanf("%d",&T);
    while ( T-- )
    {
        int n,v;
        scanf("%d",&n);
        for ( int i = 0; i <= n; i++ ) G[i].clear();
        for ( int i = 1; i <= n; i++ ) 
        {
            scanf("%d",&v);
            G[i].push_back(v);
            G[v].push_back(i);
        }
        find_scc(n);
        for ( int i = 1; i <= n; i++ )
        {
            printf("%d ",dep[i]);
        }
        printf("\n");
    }
    return 0;
}
