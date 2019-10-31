#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[4];
ll A,B,C;


int main()
{
    for ( int i = 0; i < 4; i++ )
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+4);
    printf("%lld %lld %lld\n",a[3]-a[0],a[3]-a[1],a[3]-a[2]);
    return 0;
}
