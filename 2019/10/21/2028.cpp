#include <cstdio>

using namespace std;

long long  gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 
long long  lcm( int a, int b ){ return ( a / gcd(a,b) ) * b; }

int main()
{
    int num;
    while( scanf("%d",&num) != EOF )
    {
        int a,b;
        long long ans;
        scanf("%d %d",&a,&b);
        num -= 2;
        ans = lcm( a,b );
        while( num -- )
        {
            scanf( "%d",&a );
            ans = lcm( ans,a );
        }
        printf("%lld\n",ans);
    }    
        
    return 0;
}
