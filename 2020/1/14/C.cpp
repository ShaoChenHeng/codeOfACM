#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;
int n;
int arr[60][60];

int check( int x, int y , int sum)
{
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= n; j ++ )
        {
            if ( arr[x][i] + arr[j][y] == sum )  return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    int flag = 1;
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= n; j ++ )
        {
            scanf("%d", &arr[i][j] );
        }
    }
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= n; j ++ )
        {
            if ( arr[i][j] != 1 ) 
            {
                if ( !check(i,j, arr[i][j]) )
                {
                    flag = 0;
                    break;
                }
            }
        }
    }
    if ( flag ) printf("Yes\n");
    else printf("No");
    return 0;
}
