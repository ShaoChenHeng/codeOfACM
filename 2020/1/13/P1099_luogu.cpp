#include <bits/stdc++.h>
using namespace std;
const int  INF = 1000000;

struct edge
{
    int cost, next, to;
} e[350];

long long int n, s;
int num, head[1000], edge[310][310];
int dis[310], vis[310];
int node, dep, ans = INF;
int debug = 0, bug = 0;
vector<int> G[310];
vector<int> dia_q, temp_q;
deque<int> dia_temp;

void build( int u, int v, int w )
{
    e[++num].cost = w;
    e[num].next = head[u];
    head[u] = num;
    e[num].to = v;
}

void dfs( int from, int father, int cur_dep)
{
    int d = G[from].size();
    int next = head[from].next;
    if ( d == 1 && father ==  next)
    {
        if ( cur_dep > dep )
        {
            dep = cur_dep;
            node = from;
        }
        return;
    }
    for ( int i = head[from]; i ; i = e[i].next )
    {
        int to = e[i].to;
        if ( to == father ) continue;
        dfs( to, from, cur_dep + e[i].cost );
    }
}

void dfs_dia( int from, int father, int cur_dep )
{
    int d = G[from].size();
    int next = G[from][0];
    if ( d == 1 && father ==  next)
    {
        //printf("hello");
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
        //printf("hello\n");
        int to = G[from][i];
        if ( to == father || vis[to] ) continue;
        max_edge = max( max_edge, edge[from][to] + dfs_edge( to, from ) );
        //printf("max_edge = %d\n", max_edge);
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
                //printf("hello\n");
                //printf("dist = %d", dis[dia_temp[j]] - dis[dia_temp[i]]);
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
                //printf("max_edge = %d\n",max_edge);
                if ( max_edge < ans ) 
                {
                    ans = max_edge;
                    //printf("l = %d r = %d ",dia_temp[i], dia_temp[j]);
                }
            }
            else break;
            //sum += edge[dia_temp[i]][dia_temp[j]];
            /* if ( sum > s )
            {
                dp[dia_temp[i]][dia_temp[j]] = min( dp[dia_temp[i+1]][dia_temp[j]], dp[dia_temp[i]][dia_temp[j-1]] );
                dp[dia_temp[j]][dia_temp[i]] = dp[dia_temp[i]][dia_temp[j]];
            }
            else
            {
                int max_edge = 0;
                for ( int k = i; k <= j; k ++ )
                {
                    max_edge = max( max_edge, dfs_edge( dia_temp[k], -1 ) );
                }
                printf("here\n"); 
                printf("max_edge = %d\n", max_edge);

                dp[dia_temp[i]][dia_temp[j]] = min(max_edge, min( dp[dia_temp[i+1]][dia_temp[j]], dp[dia_temp[i]][dia_temp[j-1]] ));
                dp[dia_temp[j]][dia_temp[i]] = dp[dia_temp[i]][dia_temp[j]];
                printf("%d\n",dp[dia_temp[i]][dia_temp[j]]);
            } */
            
        }
    }

    /* if ( dp[from][to] ) return dp[from][to];
    else
    {
        int sum = 0;
        for ( int i = 0; i < dia_temp.size() - 1; i ++  )
        {
            sum += edge[dia_temp[i]][dia_temp[i+1]];
            //printf("hello\n");
        }
        if ( sum > s ) 
        {
            printf("debuug%d\n",debug++);
            int beg, beg_, end, end_;
            if( !dia_temp.empty() ) beg = dia_temp.front(),dia_temp.pop_front();
            beg_ = dia_temp.front();
            end = dia_temp.back();
            int from1_to = find_ans(beg_,end);
            dia_temp.push_front(beg);
            
            end = dia_temp.back();
            dia_temp.pop_back();
            int end_ = dia_temp.back();
            beg = dia_temp.front();
            int from_to1 = find_ans(beg, end_);
            dia_temp.push_back(end);

            dp[from][to] = min( from1_to, from_to1 );
            dp[to][from] = dp[from][to];
            printf("buug%d\n",debug++);
            return dp[from][to];
        }
        else
        {
            if( dia_temp.empty() ) return INF;
            int max_edge = 0;
            for ( int i = 0; i < dia_temp.size(); i ++  )
            {
                max_edge = max( max_edge, dfs_edge(dia_temp[i], -1) );
            }

            int beg = dia_temp.front();
            dia_temp.pop_front();
            int beg_ = dia_temp.front();
            int end = dia_temp.back();
            int from1_to = find_ans(beg_,end);
            dia_temp.push_front(beg);
            
            end = dia_temp.back();
            dia_temp.pop_back();
            int end_ = dia_temp.back();
            beg = dia_temp.front();
            int from_to1 = find_ans(beg, end_);
            dia_temp.push_back(end);

            dp[from][to] = min( max_edge, min( from1_to, from_to1 ) );
            dp[to][from] = dp[from][to];
            printf("%d\n",dp[from][to]);
            return dp[from][to];
        }
        
    }
     */

}

int main()
{
    scanf("%d %d", &n, &s);
    int from, to, cost;
    for ( int i = 0; i < n - 1; i ++ )
    {
        scanf("%d %d %d", &from, &to, &cost);
        //build( from, to, cost );
        G[from].push_back(to);
        G[to].push_back(from);
        build( from, to, cost );
        build( to, from, cost );
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
    //printf("%d %d\n", deepest1, deepest2);
    dis[dia_q[0]] = 0;
    dia_temp.push_back(dia_q[0]);
    for ( int i = 1; i < dia_q.size() ; i ++ ) 
    {
        dia_temp.push_back(dia_q[i]);
        dis[dia_q[i]] = dis[dia_q[i-1]] + edge[dia_q[i-1]][dia_q[i]];
    }
    /* for ( int i = 0; i < dia_temp.size(); i ++ ) 
    {
        printf("dis%d = %d\n", dia_temp[i] , dis[dia_temp[i]]);
    } */
    find_ans();
    printf("%d\n",ans);

    return 0;
}
