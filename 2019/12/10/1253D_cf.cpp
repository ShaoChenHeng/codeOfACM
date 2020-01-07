    #include <bits/stdc++.h>

    using namespace std;
    const int maxn = 2e5 + 100;

    int n,m;
    int fa[maxn];

    void init( int n )
    {
        for ( int i = 0; i <= n; i ++  ) fa[i] = i;
    }

    int find( int x )
    {
        if ( x == fa[x] ) return x;
        return fa[x] = find(fa[x]);
    }

    int unite( int x, int y )
    {
        x = find(x);
        y = find(y);
        if ( x == y ) return 0;
        if ( x < y ) fa[x] = y;
        else fa[y] = x;
        return 1;
    }

    int main()
    {
        scanf("%d %d", &n ,&m);
        init(n);
        int u, v, ans = 0;
        for ( int i = 0; i < m; i ++ )
        {
            scanf("%d %d",&u, &v);
            unite(u,v);
        }
        int x = 0, y;
        for ( int i = 1; i <= n; i ++ )
        {
            y = find(i);
            x = max( x, y );
            if ( unite(x, y) ) ans ++;
        }
        printf("%d\n",ans);

        return 0;
    }
