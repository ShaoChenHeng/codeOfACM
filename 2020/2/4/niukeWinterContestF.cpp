#include <bits/stdc++.h>

using namespace std;

struct _pair
{
    int a, b;
};

int n, ans = 0;
string ss;
vector<int> G[100010];
map<int, int> m[100010];

void dfs( int u, int f, int cur, int root, int dep)
{
    int d = G[u].size();
    for ( int i = 0; i < d; i ++ )
    {
        int to = G[u][i];
        if ( root == -1 ) root = to;
        if ( to == f ) continue;
        if ( ss[to-1] == 'B' && cur == 0  ) 
        {
            if ( !m[root][to] && !m[to][root] && dep >= 2)
            {
                m[root][to] = 1;
                m[to][root] = 1;
                ans ++;
            }
            dfs(to, u, 1, root, dep + 1);
        }
        else if ( ss[to-1] == 'W' && cur == 1 )
        {
            if ( !m[root][to] && !m[to][root] && dep >= 2)
            {
                m[root][to] = 1;
                m[to][root] = 1;
                ans ++;
            }
            dfs(to, u, 1, root, dep + 1);
        }
        else if ( ss[to-1] == 'B' && cur == 1 )
        {
            return;
        }
        else dfs(to, u, 0, root, dep + 1);
    }
}

int main()
{
    scanf("%d", &n);
    cin >> ss;
    int u, v;
    for ( int i = 1; i < n ; i ++ )
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for ( int i = 1; i <= n; i ++ ) G[0].push_back(i);
    dfs(0, -1, 0, -1, 0);
    printf("%d\n",ans);
    return 0;
}
