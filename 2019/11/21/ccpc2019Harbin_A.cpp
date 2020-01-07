#include <bits/stdc++.h>

using namespace std;

const int maxn = 3005;
const int maxm = 100005;
int n, m1, m2, tot;
int head[maxn], dis[maxn], inq[maxn], cnt[maxn];

struct opt
{
    int l, r, w;
} a[maxn], b[maxn];

struct edge
{
    int u, v, w, type, next;
} e[maxm];

void add_edge( int u, int v, int w, int t )
{
    e[++tot] = edge{ u, v, w, t, head[u] };
    head[u] = tot;
}

struct dequeue_
{
    int a[maxn], L, R, siz = 0;
    
    bool empty() { return siz == 0; }
    dequeue_( int l = 1, int  r = 0, int siz_ = 0)
    {
        L = l, R = r, siz = siz_;        
    }
    
    void clear() { L = 1, R = 0, siz = 0; }
    
    bool push_front ( int val )
    {
        if ( siz == maxn - 1 ) return false;
        if ( L == 1 ) L = maxn - 1, a[L] = val, siz ++;
        else L --, a[L] = val,siz ++;
        return true;
    }

    bool push_back( int val )
    {
        if ( siz == maxn - 1 ) return false;
        if ( R == maxn - 1 ) R = 1, a[R] = val, siz ++;
        else R ++, a[R] = val, siz ++;
        return true;
    }    

    int pop_front()
    {
        if ( siz == 0 ) return 0;
        int ans = 0;
        if ( L == maxn - 1 ) ans = a[L], L = 1, siz --;
        else ans = a[L], L ++, siz --;
        return ans;
    }

    int pop_back()
    {
        if ( siz == 0 ) return 0;
        int ans = 0;
        if ( R == 1 ) ans = a[R], R = maxn - 1, siz --;
        else ans = a[R], R --, siz --;
        return ans;
    }

    int front() { return a[L]; }
    int back() { return a[R]; }
    
};

bool spfa( int s, int mid )
{
    for ( int i = 0; i <= n; i ++ ) dis[i] = 0x3f3f3f, inq[i] = 0, cnt[i] = 0;
    //queue<int> que;
    dequeue_ que;
    que.push_front(s);
    inq[s] = 1, dis[s] = 0, cnt[0] = 1;
    while ( !que.empty() )
    {
        int cur = que.front();
        que.pop_front();
        inq[cur] = 0;
        for ( int i = head[cur]; i; i = e[i].next )
        {
            int weight = e[i].type ? mid + e[i].w : e[i].w;
            if ( dis[e[i].v] > dis[e[i].u] + weight )
            {
                dis[e[i].v] = dis[e[i].u] + weight;
                if ( dis[e[i].v] < 0 ) return false;
                if ( !inq[e[i].v] )
                {
                    if ( !que.empty() && dis[e[i].v] >= dis[que.front()]) que.push_back(e[i].v);
                    else que.push_front( e[i].v );
                    cnt[e[i].v] ++, inq[e[i].v] = 1;
                    if ( cnt[e[i].v] > n ) return false;
                }
            }
        }
    }
    return true;
}

bool check( int mid )
{
    e[tot].w = -mid, e[tot-1].w = mid;
    return spfa(0, mid);
}

int main()
{
    int t;
    scanf("%d", &t);
    while ( t -- )
    {
        scanf("%d %d %d", &n, &m1, &m2);
        for ( int i = 1; i <= m1; i++ ) scanf("%d %d %d",&a[i].l, &a[i].r, &a[i].w);
        for ( int i = 1; i <= m2; i++ ) scanf("%d %d %d",&b[i].l, &b[i].r, &b[i].w);
        for ( int i = 1; i <= n; i ++ ) add_edge( i, i - 1, 0, 0 ), add_edge( i - 1, i, 1, 0 );
        // sum[i - 1] - sum[i] <= 0
        // sum[i] - sum[i - 1] <= 1
        for ( int i = 1; i <= m1; i++ ) add_edge( a[i].r, a[i].l - 1, -a[i].w, 0 ); // sum[l[i] - 1] - sum[r[i]] <= -k[i]
        for ( int i = 1; i <= m2; i++ ) add_edge( b[i].l - 1, b[i].r, -b[i].w, 1 ); // sum[r[i]] - sum[l[i] - 1] <= mid - k[i]
        add_edge( 0, n, 0, 0 ), add_edge( n, 0, 0, 0 );
        int l = 0, r = n, ans = -1;
        while ( l <= r )
        {
            int mid = l + ( ( r - l ) >> 2 );
            if ( check(mid) ) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        printf("%d\n",ans);
        for ( int i = 0; i <= n; i++ ) head[i] = 0;
        tot = 0;

    }

    return 0;
}
