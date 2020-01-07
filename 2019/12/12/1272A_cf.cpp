#include <bits/stdc++.h>

using namespace std;

int q;

int main()
{
    long long int a,b,c,dis = 0;
    scanf("%d",&q);
    while ( q-- )
    {
        dis = 0;
        scanf("%lld %lld %lld", &a, &b, &c);
        dis += ( abs(a - b) + abs( a - c ) + abs( b - c ) );
        //printf("dis = %lld\n",dis);
        if ( dis <= 4 )printf("0\n");
        else printf("%lld\n", dis - 4);

    }
    return 0;
}
