#include <cstdio>
#include <algorithm>

using namespace std;

int a[150];
int n,m;

int main()
{
    while ( scanf("%d %d", &n,&m) != EOF && n && m )
    {
        for ( int i = 0; i < n; i ++ )
        {
            scanf("%d",a+i);
        }
        a[n] = m;
        sort(a,a+n+1);
        for ( int i = 0; i <= n ; i++  )
        {
            if( i != n ) printf("%d ",a[i]);
            else printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
