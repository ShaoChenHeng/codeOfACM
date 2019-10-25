#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool used[7];
int a[7],b[7];
bool flag,ff;

void dfs( int num )
{
    if ( num == 4 )
    {
        if ( ff ) printf(" ");
        for ( int i = 1; i <= 4; i++ ) printf("%d",b[i]);
        ff = 1;
        return ;
    }
    int tmp = -1;
    for( int i = 1; i <= 4; i ++ )
    {
        if ( a[i] != tmp && !used[i] )
        {
            used[i] = 1;
            tmp = a[i];
            b[num + 1] = a[i];
            dfs(num+1);
            used[i] = 0;
        }
    }
}

int main()
{
    for( int i = 1; i <= 4; i ++ ) scanf("%d",&a[i]);
    while ( 1 )
    {
        memset( used, 0, sizeof(used) );
        sort( a+1, a+5 );
        int temp = -1;
        for( int i = 1; i <= 4; i++ )
        {
            if ( a[i] && a[i] != temp )
            {
                ff = 0;
                used[i] = 1;
                temp = a[i];
                b[1] = a[i];
                dfs(1);
                printf("\n");
                used[i] = 0;
            }
        }

        for ( int i = 1; i <= 4; i ++ ) scanf("%d",&a[i]);
        flag = 0;
        for ( int i = 1; i <= 4; i ++ ) if( a[i] ) flag = 1;
        if ( flag ) printf("\n");
        else break;
    }
    
    return 0;
}
