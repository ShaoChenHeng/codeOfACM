#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[5010];

int main()
{
    scanf("%d %d", &n, &k);
    int num;
    a[0] = 0;
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d",&num);
        a[i] = a[i-1] + num;
    }
    double ave = -1;
    for ( int i = 0; i <= n; i ++ )
    {
        for ( int j = k + i; j <= n; j ++ )
        {
            ave = max( ( a[j] - a[i] ) * 1.0  / ( j - i ) , ave);
        }
    }
    printf("%.15lf",ave);
    return 0;
}
