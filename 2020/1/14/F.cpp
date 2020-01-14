#include <bits/stdc++.h>

using namespace std;


int m, b;

int main()
{
    scanf("%d %d", &m, &b);
    long long int ans = 0, temp = 0;
    for ( int i = 0, j = b ; j >= 0; i += m, j -- )
    {
        temp = 0;
        for ( int l = 0; l <= i; l ++ )
        {
            for ( int r = 0; r <= j; r ++ )
            {
                temp += l + r;
            }
        }
        ans = max( ans, temp );
    }
    printf("%lld\n",ans);
    return 0;
}
