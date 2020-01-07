#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    int son, father, branch_father, deep;
    bool is_cover;
    Tree ( int father = -1, int deep = 0 ) : father(father) , deep(deep) {}
} tree[50010];

int n,k;
int meizi[50010];
int vis[50010];
vector<int> deep[50010];
map<int, int> vis;



int main()
{
    scanf("%d %d",&n, &k);
    int u, v;
    tree[1].father = -1;
    tree[1].deep = 0;
    for ( int i = 0; i < n - 1; i++ )
    {
        scanf("%d %d",&u, &v);
        tree[u].son = v;
        tree[v].father = u;
        tree[u].deep = tree[tree[u].father].deep + 1;
        tree[v].deep = tree[u].deep + 1;
        tree[u].is_cover = false;
        tree[v].is_cover = false;
    }
    int sum_branch = 0;
    for ( int i = 1; i <= k; i++ )
    {
        scanf("%d", &meizi[i]);
        tree[meizi[i]].is_cover = true;
        deep[tree[meizi[i]].deep].push_back(meizi[i]);
    }

    /* 
    int pos;
    vis[0] = 1;
    for ( int i = 1; i <= k; i ++ )
    {
        pos = meizi[i].pos;
        while ( !vis.count(tree[pos]) && pos >= 1 )
        {
            pos = tree[pos];       
        }
        vis[pos] = 1;
    }
    map<int, int>::iterator ite;
    int node, ans = 0, deep = 0;
    ite = vis.begin();
    ite ++;
    for ( ; ite != vis.end(); ite++ )
    {
        deep = 0;
        node = ite -> first;
        while ( tree[node] > 0 )
        {
            node = tree[node];
            deep ++;
            //printf("deep = %d\n",deep);
        }
        ans += deep;
    }
    printf("%d\n",ans); */
    return 0;
}
