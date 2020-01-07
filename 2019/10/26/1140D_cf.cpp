#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,sum = 0;
    scanf("%d",&n);
    for ( int i = 3; i <= n; i++ )
    {
        sum = sum + i * ( i - 1 );
    }
    printf("%d\n",sum);

    return 0;
}
