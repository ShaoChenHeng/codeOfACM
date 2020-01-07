#include <bits/stdc++.h>

using namespace std;

long long  b = 1000000000;

long long s(long long x)
{
    int ans = 0;
    int num;
    while ( x > 0 )
    {
        num = x % 10;
        x /= 10;
        ans += num;
    }
    return ans;
}

int main()
{
    freopen("out.txt", "w", stdout);
    int sum = 0;
    for ( int i = 1; i <= b; i++ )
    {
        if ( s(i) * s(i) == s(i * i) )
        {
            sum ++;
            printf("%d,",sum);
        }
        else
        {
            printf("%d,",sum);
        }
    }
    fclose(stdout);
    return 0;
}
