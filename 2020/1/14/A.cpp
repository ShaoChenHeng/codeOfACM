#include <bits/stdc++.h>

using namespace std;

int return_tier( int num )
{
    int ans = 0;
    while ( num > 0 )
    {
        num /= 2;
        ans ++;
    }
    return ans;
}

int main()
{
    int n, q;
    scanf("%d", &n);
    printf("%d\n", return_tier(n));
    return 0;
}
