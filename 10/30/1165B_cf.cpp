#include <bits/stdc++.h>

using namespace std;

int n;
int a[200020];

int main()
{
    scanf("%d",&n);
    int ans = 1;
    for ( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for( int i = 1; i <= n; i++ )
    {
        if ( a[i] >= ans ) ans ++;
    }
    cout << ans - 1<<endl;

    return 0;
}

