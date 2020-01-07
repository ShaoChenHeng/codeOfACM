#include <cstdio>
#include <iostream>

using namespace std;

long long gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 
long long lcm( int a, int b ){ return a/gcd(a,b)*b; }

int n;

int main()
{
    long long a,b;    
    /* while(scanf("%d",&n) != EOF)
    { */
    cin >> n;
    while ( n-- )
    {
        int m;
        scanf("%d",&m);
        scanf("%lld %lld",&a,&b);
        a = lcm( a,b );
        for ( int i =1; i < m; i++ )
        {
            scanf("%lld",&b);
            a = lcm( a,b );
        }
        printf("%lld\n",a);
    }
    
    return 0;
}
