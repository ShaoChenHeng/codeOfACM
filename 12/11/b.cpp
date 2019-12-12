#include <bits/stdc++.h>

using namespace std;

int n;
long long int vis[1000];

long long int f1( int x )
{
    long long int sum = 0;
    if (x == 1  ) return 1;
    if ( vis[x] ) return vis[x];
    else
    {
        for ( int i = 1; i <= x -1; i ++ )
        {
            vis[i] = f1(i);
            sum += ( x - i ) * f1(i);
        }
        return sum;
    }
}

int f( int x )
{
    if (x == 1  ) return 1;
    else
    {
        int sum = 0;
        for ( int i = 1; i <= x -1; i ++ )
        {
            sum += ( x - i ) * f(i);
        }
        return sum;
    }
}

int main()
{
    //memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    //for ( int i = 1; i <= 10; i ++ ) 
    printf("%lld\n",f1(n));
    return 0;
}
