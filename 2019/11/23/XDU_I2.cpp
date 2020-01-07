#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    int deep, num;
    bool is_covered;
    Tree ( int deep = 0, bool is_covered = false ) : deep(deep), is_covered(is_covered) {}
};

int n, k;
int meizi[50010];
bool is_coverd[50010];
int deep[50010];
int vis[50010];
vector<int> tree[50010];

void dfs( int u, int dep )
{
    vis[u] = 1;
    deep[u] = dep;
    if (  )
    int d = tree[u].size();
    for ( int i = 0; i < d; i ++ )
    {
        int v = tree[u][i];
        if ( !vis[v] ) dfs (v, dep + 1);
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d %d",&n, &k);
    int u,v;
    for ( int i = 1; i < n; i ++ )
    {
        scanf("%d %d",&u, &v);
        tree[u].push_back(v);
    }
    dfs(1,0);
    int mz;
    for ( int i = 0; i < k; i ++ )
    {
        scanf("%d",&meizi[i]);
        is_coverd[meizi[i]] = true;
    }
    /* for ( int i = 1; i <= n; i++ ) 
    {
        printf("num = %d deep = %d is_cover = %d\n",i, deep[i], is_coverd[i]);
    } */
    int sum_branch = 0;
    

    while ( sum_branch != 0 )
    {

    }

    return 0;
}
