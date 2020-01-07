#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,pw[1000005],ans,T,num;
bool inq[100];

int main()
{
    pw[0] = 1;
    //printf("%lld",pw[0]);
    for(int i = 1; i <= 38; ++i) pw[i] = pw[i - 1] * 3;
    scanf("%lld",&n);
    while ( n -- )
    {
        scanf("%lld",&num);
        ans = 0;
        for ( int i = 0; i <= 38; i++ ) inq[i] = 0;
        for ( int i = 38; i >= 0; i-- ) 
        {
            if ( num > pw[i] )
            {
                num -= pw[i];
                ans += pw[i];
                inq[i] = 1;
            }
        }
        for ( int i = 0; i <= 38; i++ )
        {
            if ( inq[i] ) ans -= pw[i];
            else 
            {
                ans += pw[i];
                break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
