#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int a[100];
int b[100];

int main()
{
    while ( scanf("%d %d",&n,&m) != EOF && n && m )
    {
        for ( int i = 0; i < n; i++ ) scanf( "%d",&a[i] );
        for ( int i = 0; i < m; i++ ) scanf( "%d",&b[i] );
        sort ( a, a + n );
        sort ( b, b + m );
        if ( a[0] < b[1] ) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
