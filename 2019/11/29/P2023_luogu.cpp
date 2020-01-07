#include <bits/stdc++.h>
#define INF 0x3f3f3f
#define MAXN 5000010
using namespace std;

int N, P;
int sumv[MAXN], addv[MAXN];
int _y1, _y2, _sum, v;

void maintain( int o, int L, int R )
{
    int lc = o * 2, rc = o * 2 + 1;
    sumv[o] = 0;
    if ( R > L )
    {
        sumv[o] = sumv[lc] + sumv[rc];
    }
    sumv[o] += addv[o] * ( R - L + 1 );
}

void update( int o, int L, int R )
{
    int lc = o * 2, rc = o * 2 + 1;
    if ( _y1 <= L && _y2 >= R ) addv[o] += v;
    else
    {
        int M = L + ( R - L ) / 2;
        if ( _y1 <= M ) update( lc, L, M );
        if ( _y2 > M ) update( rc, M + 1, R );
    }
    maintain( o, L, R );
}

void query( int o, int L, int R, int add )
{
    if ( _y1 <= L && _y2 >= R )
    {
        _sum += sumv[o] + add * ( R - L + 1 );
    }
    else
    {
        {
            int M = L + ( R - L ) / 2;
            if ( _y1 <= M ) query( o * 2, L, M, add + addv[o] );
            if ( _y2 > M ) query( o * 2 + 1, M + 1, R, add + addv[o] );
        }
    }
}

int main()
{
    int q, type, num;
    scanf("%d %d",&N, &P);
    for ( int i = 1; i <= N; i ++ )
    { 
        _y1 = i, _y2 = i;
        scanf("%d",&v);
        update(1, 1, N);
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", type);
        if ( type == 1 )
        {
            scanf("%d %d %d",&_y1, &_y2, &num );
            update(  )
        }
    }
    //query(1, 1, n, 0);

    return 0;
}
