#include <bits/stdc++.h>

using namespace std;

int n, T;
long long int a[100010];

int main()
{
    scanf("%d", &T);
    while (T --  )
    {
        long long int sum = 0;
        scanf("%d",&n);
        for ( int i = 0; i < n; i ++ ) 
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        
        long long int sum1 = 0, sum2 = 0, flag = 1;
        for ( int  i = 0; i < n; i ++ )
        {
            sum1 += a[i];
            if ( sum1 <= 0 ) flag = 0;
        }
        for ( int  i = n - 1; i >= 0; i -- )
        {
            sum2 += a[i];
            if ( sum2 <= 0 ) flag = 0;
        }

        if ( !flag  ) printf("NO\n");
        else printf("YES\n");

    }

    return 0;
}
