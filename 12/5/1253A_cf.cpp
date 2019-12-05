#include <bits/stdc++.h>

using namespace std;

int q,n;
int a[100010], b[100010];

int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        scanf("%d",&n);
        for ( int i = 1; i <= n; i ++ ) scanf("%d",&a[i]);
        for ( int i = 1; i <= n; i ++ ) scanf("%d",&b[i]);
        int pos = 0, dis = 0, flag1 = 0, flag2 = 0;
        for ( int i = 1; i <= n; i ++ )
        {
            if ( a[i] != b[i] && flag1 == 0 ) 
            {
                pos = i;
                dis = b[i] - a[i];
                if ( dis < 0 )
                {
                    flag2 = 1;
                    break;
                }
                flag1 = 1;
            }
            else if ( a[i] != b[i] && flag1 == 1 )
            {
                if ( b[i] - a[i] != dis  || i != pos + 1 )
                {
                    flag2 = 1;
                    break;
                }
                else pos = i;
            }
        }
        if ( flag2 ) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
