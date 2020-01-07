#include <bits/stdc++.h>

using namespace std;

int n,q;
int a[200010];
int pre[200010];

int main()
{
    scanf("%d",&q);
    while( q -- )
    {
        scanf("%d",&n);
        int minn = 200010;
        memset(pre, -1, sizeof(pre));
        for ( int i = 1; i <= n; i ++ ) scanf("%d",&a[i]);
        for ( int i = 1; i <= n; i++ )
        {
            if ( pre[a[i]] != -1 ) minn = min( minn, i - pre[a[i]] + 1 );
            pre[a[i]] = i;
        }
        if ( minn == 200010 ) minn = -1;
        printf("%d\n",minn);
    }

    return 0;
}
