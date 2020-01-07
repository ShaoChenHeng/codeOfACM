#include<bits/stdc++.h>

using namespace std;

int q, n;
int a[200010];
int p[200010];

int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        int ans = 0;
        scanf("%d",&n);
        for ( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        sort(a + 1,a + n + 1);
        for ( int i = 1; i <= n; i++ ) p[i] = i - 1;
        for ( int i = 1; i <= n; i ++ )        
        {
            int sum = a[i], s = 1, x = i;
            while ( s < 3 && x )
            {
                if ( a[i] % a[x] ) s ++, sum += a[x];
                while ( p[x] && a[i] % a[p[x]] == 0 ) p[x] = p[p[x]];
                x = p[x];
            }
            ans = max( ans, sum );
        }
        printf("%d\n",ans);
    }

    return 0;
}
