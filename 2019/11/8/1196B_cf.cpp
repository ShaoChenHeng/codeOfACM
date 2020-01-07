#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int q, n, k;
int a[200010];

int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        int cnt = 0, pos, sum = 0;
        scanf("%d %d",&n,&k);
        for ( int i = 1; i <= n; i++ )
        {
            scanf("%d",&a[i]);
            if ( a[i] % 2 )
            {
                cnt ++;
            } 
        }
        if ( cnt < k || ( cnt - k ) % 2 ) printf("NO\n");
        else
        {
            printf("YES\n");
            int pos = 1;
            while ( k > 1 )
            {
                if ( a[pos] % 2 )
                {
                    printf("%d ",pos);
                    k --;
                }
                pos ++;
            }
            printf("%d\n",n);
        }
    }
    return 0;
}

