#include <bits/stdc++.h>
#define INF 0x3f3f3f

using namespace std;

int m, di, ql, qr;
int v, p;
int maxv[800005];

int query( int o, int L, int R )
{
    int M = L + ( R - L ) / 2, ans = -INF;
    if ( ql <= L &&  R <= qr ) return maxv[o];
    if ( ql <= M ) ans = max( ans, query( o * 2, L, M ) );
    if ( M < qr ) ans = max( ans, query( o * 2 + 1, M + 1, R ) );
    return ans;
}

void update( int o, int L, int R )
{
    int M = L + ( R - L ) / 2;
    if ( L == R ) maxv[o] = v;
    else
    {
        if ( p <= M ) update( o * 2, L, M );
        else update( o * 2 + 1, M + 1, R );
        maxv[o] = max( maxv[o * 2], maxv[o * 2 + 1] );
    }
}    

int main()
{
    char ch[2];
    scanf("%d %d",&m, &di);
    int num, t = 0;
    int left, right;
    right = 0;
    for( int i = 1; i <= m; i ++ )
    {
        scanf("%s %d",ch, &num);
        if ( ch[0] == 'A' )
        {
            right ++;
            p = right;
            v = ( num + t ) % di;
            //printf("v = %d\n", v);
            update( 1, 1, m);
            //printf("hello");
        }
        if ( ch[0] == 'Q' )
        {
            //printf("hello");
            ql = right - num + 1, qr = right;
            if ( num == 0 ) t = 0;
            else t = query(1, 1, m);
            printf( "%d\n", t);
        }
//        for ( int i = 1; i < 10; i++) printf("%d ", maxv[i]);
    }
    return 0;
}
