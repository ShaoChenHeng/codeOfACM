#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];

int main()
{
    scanf("%d",&n);
    int l = 1, sum = 0;
    for ( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
    while ( l <= n )
    {
        if ( a[l] == 0 && a[l + 1] == 0)
        {
            l += 2;
            sum += 1;
        }
        else
        {
            sum += a[l];
            l ++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
