#include<bits/stdc++.h>

using namespace std;

struct pp
{
    int l,r,t;
    //t表示编程能力
    //l前指针
    //r后指针
} a[200010];

struct pa
{
    int t,num;
} b[200010];

int n,k,ans[200010];
bool vis[200010];

bool cmp( pa a1, pa a2 )
{
    return a1.t > a2.t;
}

int main()
{
    scanf("%d %d",&n,&k);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d",&a[i].t);
        a[i].l = i - 1;
        a[i].r = i + 1;
        b[i].num = i;
        b[i].t = a[i].t;
    }
    sort( b + 1, b + 1 + n, cmp );
    int top = 1, x = 1;
    // x记录1/2教练
    while ( top <= n )
    {
        while ( vis[b[top].num] ) top ++;
        int g = b[top].num;
        int ll = a[g].l, rr = a[g].r;
        ans[g] = ( x % 2 == 0 ? 2 : 1 );
        vis[g] = 1;
        for ( int i = 1; i <= k && ll != 0; i ++ )
        {
            ans[ll] = ( x % 2 == 0 ? 2 : 1 );
            vis[ll] = 1;
            ll = a[ll].l;
        }
        for ( int i = 1; i <= k && rr != n + 1; i ++)
        {
            ans[rr] = ( x % 2 == 0 ? 2 : 1 );
            vis[rr] = 1;
            rr = a[rr].r;
        }
        a[rr].l = ll;
        a[ll].r = rr;
        x ++;
    }
    for ( int i = 1; i <= n; i++ ) printf("%d",ans[i]);
    return 0;
}
