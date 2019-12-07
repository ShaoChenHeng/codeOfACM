#include <bits/stdc++.h>

using namespace std;

int q;
long long int n;

int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        long long cnt = 0;
        scanf("%lld", &n);
        if ( n == 1 ) printf("1\n");
        else 
        {
            while ( n > 0 )
            {
                n /= 2;
                cnt ++;
            }
            printf("%lld\n",cnt - 1);
        }
        
    }
    return 0;
}
