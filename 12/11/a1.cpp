#include <bits/stdc++.h>

using namespace std;

int n,q;

struct meizi
{
    int a, b, pos;
    string name;
} m[1010];

int cmp ( meizi x, meizi y )
{
    if ( x.a != y.a ) return x.a > y.a;
    else
    {
        if ( x.b != y.b ) return x.b > y.b;
        return x.name < y.name;
    }
}

int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        int pos[1010];
        scanf("%d",&n);
        for ( int i = 1; i <= n; i ++ )
        {
            cin >> m[i].name;
            scanf("%d %d",&m[i].a, &m[i].b);
            m[i].pos = i;
        }
        sort( m + 1, m + 1 + n, cmp );
        for ( int i = 1; i <= n; i ++ ) pos[m[i].pos] = i;
        for ( int i = 1; i <= n; i ++ ) printf("%d ", pos[i]);
        printf("\n");
    }

    return 0;
}
