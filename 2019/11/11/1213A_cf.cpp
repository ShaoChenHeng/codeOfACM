#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll a[2];

int main()
{
    scanf("%d",&n);
    int num;
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d",&num);
        if ( num % 2 ) a[0] ++;
        else a[1] ++;
    } 
    printf("%lld\n",min(a[0],a[1]));

    return 0;
}
