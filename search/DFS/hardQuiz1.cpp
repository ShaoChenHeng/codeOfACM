#include <bits/stdc++.h>
using namespace std;
const int  INF = 1000000;

int n, s;
int num, edge[310][310];
int dis[310], vis[310];
int node, dep, ans = INF;
vector<int> G[310];
vector<int> dia_q, temp_q;
deque<int> dia_temp;


void dfs( int from, int father, int cur_dep)
{
    int d = G[from].size();
    int next = G[from][0];
    if ( d == 1 && father ==  next)
    {
        if ( cur_dep > dep )
        {
            dep = cur_dep;
            node = from;
        }
        return;
    }
    for ( int i = 0; i < d; i ++ )
    {
        int to = G[from][i];
        if ( to == father ) continue;
        dfs( to, from, cur_dep + edge[from][to] );
    }
}

void dfs_dia( int from, int father, int cur_dep )
{
    int d = G[from].size();
    int next = G[from][0];
    if ( d == 1 && father ==  next)
    {
        if ( cur_dep > dep )
        {
            dep = cur_dep;
            node = from;
            dia_q = temp_q;
        }
        return ;
    }
    for ( int i = 0; i < d; i ++ )
    {
        int to = G[from][i];
        if ( to == father ) continue;
        temp_q.push_back(to);
        dfs_dia( to, from, cur_dep + edge[from][to] );
        temp_q.pop_back();
    }
}

int dfs_edge(int from, int father)
{
    int d = G[from].size();
    int next = G[from][0];
    if ( d == 1 && next == father || d == 0)
    {
        return 0;
    }
    int max_edge = 0;
    for ( int i = 0; i < d; i ++ )
    {
        int to = G[from][i];
        if ( to == father || vis[to] ) continue;
        max_edge = max( max_edge, edge[from][to] + dfs_edge( to, from ) );
    }
    return max_edge;
}

void find_ans(  )
{
    for (int i = 0 ; i < dia_temp.size(); i ++  )
    {
        for ( int j = i; j < dia_temp.size(); j ++ )
        {
            if ( dis[dia_temp[j]] - dis[dia_temp[i]] <= s )
            {
                
                memset( vis, 0, sizeof(vis) );
                for ( int k = i; k <= j; k ++ )
                {
                    vis[dia_temp[k]] = 1;
                }
                int max_edge = 0;
                for ( int k = i; k <= j; k ++ )
                {
                    max_edge = max( max_edge, dfs_edge(dia_temp[k], -1) );
                }
                if ( max_edge < ans ) 
                {
                    ans = max_edge;
                }
            }
            else break;
            
            
        }
    }

   

}

int main()
{
    scanf("%d %d", &n, &s);
    int from, to, cost;
    for ( int i = 0; i < n - 1; i ++ )
    {
        scanf("%d %d %d", &from, &to, &cost);
        G[from].push_back(to);
        G[to].push_back(from);
        edge[from][to] = cost;
        edge[to][from] = cost;
    }
    int deepest1, deepest2;

    dep = 0;
    dfs(1, -1, 0);
    deepest1 = node;
    
    temp_q.push_back(deepest1);
    dep = 0;
    dfs_dia(deepest1, -1, 0);
    deepest2 = node;
    dis[dia_q[0]] = 0;
    dia_temp.push_back(dia_q[0]);
    for ( int i = 1; i < dia_q.size() ; i ++ ) 
    {
        dia_temp.push_back(dia_q[i]);
        dis[dia_q[i]] = dis[dia_q[i-1]] + edge[dia_q[i-1]][dia_q[i]];
    }

    find_ans();
    printf("%d\n",ans);

    return 0;
}
