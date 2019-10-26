#include <bits/stdc++.h>

using namespace std;

int a[10010];

int main()
{
    int n;
    scanf("%d",&n);;
    int count = 0;
    for ( int i = 1; i <= n; i ++ ) scanf("%d",a+i);
    //for ( int i = 1; i <= n; i ++  )
    int beg = 1;
    int cur = a[1];        
    while ( beg <= n )
    {
        count ++;
        for ( int j = beg; j <= cur; j++ )
        {
            cur = max( cur, a[j] );
        }
        beg = cur +1;
        cur = a[beg];
    }
    printf("%d\n",count);
    return 0;
}
