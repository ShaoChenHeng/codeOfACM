#include <bits/stdc++.h>

using namespace std;
bitset<30> a,b(1073741823), c;

int n,m,r;
char ss[5];


int main()
{
    scanf("%d %d",&n, &m);
    for ( int i = 0; i < n; i ++ ) 
    {
        scanf("%s %d",ss, &r);
        if ( ss[0] == 'A' ) a &= r, b &= r;
        else if ( ss[0] == 'O' ) a |= r, b |= r;
        else if ( ss[0] == 'X' ) a ^= r, b ^= r;
    }

    for ( int i = 0; i <= 29; i ++ )
    {
        if ( a[i] ||  (b[i] && c.to_ulong() < m ) ) c[i] = 1;
    }
    printf("%ld", c.to_ulong());
    return 0;
}

