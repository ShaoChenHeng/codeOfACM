#include <cstdio>
#include <algorithm>

using namespace std;

int a[100];
int n;
int main()
{
    while( scanf("%d",&n) != EOF )
    {
        for ( int i = 0; i <= n; i++ ) scanf("%d",&a[i]);
        sort(a,a + n + 1);
        for ( int i = 0; i < n; i ++ ) printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}