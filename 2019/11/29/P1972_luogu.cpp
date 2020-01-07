    #include <bits/stdc++.h>

    using namespace std;

    struct node
    {
        int l, r;
        int pos;

    } q[1000010];

    int C[4000010], n, m, num[1000010], ans[1000010];
    int  vis[1000010];

    bool cmp( node a, node b )
    {
        return a.r < b.r;
    }

    int lowbit( int x ) { return x & ( -x ); }

    int sum( int x )
    {
        int ret = 0;
        while ( x > 0 )
        {
            ret += C[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void add( int x, int d )
    {
        while ( x <= n )
        {
            C[x] += d;
            x += lowbit(x);
        }
    }

    int main()
    {
        scanf("%d",&n);
        for ( int i = 1; i <= n; i++ ) scanf("%d",&num[i]);
        scanf("%d", &m);
        for ( int i = 1; i <= m; i ++ )
        {
            scanf("%d %d",&q[i].l,&q[i].r);
            q[i].pos = i;
        }
        sort( q + 1, q + m + 1, cmp);
        int next = 1;
        for ( int i = 1; i <= m; i++ )
        {
            for ( int j = next; j <= q[i].r; j ++ )
            {
                if ( vis[num[j]] ) add(vis[num[j]], -1);
                add( j, 1 );
                vis[num[j]] = j;
            }
            next = q[i].r + 1;
            ans[q[i].pos] = sum(q[i].r) - sum(q[i].l - 1);
        }
        for ( int i = 1; i <= m; i ++ ) printf("%d\n", ans[i]);

        return 0;
    }
