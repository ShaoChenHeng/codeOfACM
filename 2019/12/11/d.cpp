#include <bits/stdc++.h>

using namespace std;

int T, k;
double n;

int main()
{
    scanf("%d",&T);
    int jinl = 1, jinr;
    int yinl, yinr;
    int tongl, tongr;
    while ( T -- )
    {
        jinl = 1;
        scanf("%lf",&n);
        scanf("%d",&k);
        jinr = ceil(n * 0.1);
        yinl = jinr + 1;
        yinr = yinl + ceil( n * 0.2 ) - 1;
        tongl = yinr + 1; 
        tongr = tongl + ceil( n * 0.3 ) - 1;
        if ( k <= jinr && k >= jinl ) printf("jin\n");
        else if ( k <= yinr && k >= yinl ) printf("yin\n");
        else if ( k <= tongr && k >= tongl ) printf("tong\n");
        else printf("tie\n");
    }

    return 0;
}
