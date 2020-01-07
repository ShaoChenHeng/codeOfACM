#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

// 0 fish 1 rabbit 2 chicken
int week[] = { 0, 1, 2, 0, 2, 1, 0, };
// sum of food every week needed
int item[] = { 3, 2, 2,};
ll a[3];
ll b[3];

ll check(ll beg)
{
    memcpy(b,a,sizeof(b));
    ll restday = 0;
    for ( ll i = beg; ; i++ )
    {
        if ( i == 7 ) i %= 7;
        if ( b[week[i]] == 0 ) return restday;
        else 
        {
            b[week[i]] --;
            restday ++;
        }
    }
}

int main()
{
    ll weeks = 10000000000000;
    ll days = 0;
    ll restdays = 0;
    for ( int i = 0; i < 3; i ++ ) scanf("%lld",&a[i]);
    for ( int i = 0; i < 3; i ++ )
    {
        weeks = min( weeks, a[i] / item[i] );
    }
    days += ( weeks * 7 );
    for ( int i = 0; i < 3; i++ )
    {
        a[i] -= (item[i] * weeks);
    }
    for ( int i = 0; i < 7; i++ )
    {
        restdays = max( restdays, check(i) );
    }
    printf("%lld\n",days+restdays);

    return 0;
}
