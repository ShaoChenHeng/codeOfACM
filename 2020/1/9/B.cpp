#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 

int main()
{

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d) ;
    a *= d;
    b *= c;
    if ( a > b ) swap(a, b);
    if ( c > d ) swap(c, d);
    a = b - a;
    int div = gcd( a,  b);
    printf("%d/%d\n",a/div, b/div);

    return 0;
}
