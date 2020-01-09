#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
using namespace std;

int n, m, d;
int p[100010];
vector<int> v[100010];
int _count[100010], count1[100010], count2[100010];


void dfs( int from, int to)
{
    //printf("hello");
    int di = v[from].size();
    for ( int i = 0; i < di; i ++ )
    {
        int t = v[from][i];
        if ( to == t )  continue;
        _count[t] = _count[from] + 1;
        dfs(t, from);
    } 
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    int item;
    for ( int i = 1; i <= m; i ++ ) 
    {
        scanf("%d",&item);
        p[item] = 1;
    }
    for ( int i = 1; i <= n; i ++ ) v[i].clear();
    int from, to;

    for ( int i = 1; i <= n - 1; i ++ )
    {
        scanf("%d %d",&from, &to);
        v[from].push_back(to);
        v[to].push_back(from);
    }
    memset(_count, 0, sizeof(_count));
    dfs(1, -1);
    int _max1 = -1, pos1;
    for ( int i = 1; i <= n; i ++ )
    {
        if ( !p[i] ) continue;
        if ( _count[i] > _max1 )
        {
            _max1 = _count[i];
            pos1 = i;
        }
    }
    memset(_count, 0, sizeof(_count));
    dfs(pos1, -1);
    memcpy(count1, _count, sizeof(_count));

    int _max2 = -1, pos2;
    for ( int i = 1; i <= n; i ++ )
    {
        if ( !p[i] ) continue;
        if ( _count[i] > _max2 )
        {
            _max2 = _count[i];
            pos2 = i;
        }
    }

    memset( _count, 0, sizeof(_count) );
    dfs(pos2, -1);
    memcpy(count2, _count, sizeof(_count));

    int ans = 0;
    for ( int i = 1; i <= n; i ++ )
    {
        if ( count1[i] <= d && count2[i] <= d ) ans ++;
    }
    cout << ans<<endl;

   /*  printf("***********\n");
    printf("s = \n");
    set<int>::iterator ite;
    for ( ite = s.begin(); ite != s.end(); ite ++ )
    {
        cout << *ite <<"  ";
    }
    printf("\n");
    printf("***********\n"); */
    return 0;
}
