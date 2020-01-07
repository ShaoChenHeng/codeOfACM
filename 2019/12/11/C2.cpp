#include <bits/stdc++.h>

using namespace std;

int vis[10][10];
int ans, n, m;

bool check()
{
    int sum = 0;
    for ( int i = 0; i < n; i ++ ) 
    {
        sum = 0;
        for ( int j = 0; j < n; j ++ )
        {
            sum += vis[i][j];
            if ( sum != m ) return false;
        }
    }
    for ( int i = 0; i < n; i ++ ) 
    {
        sum = 0;
        for ( int j = 0; j < n; j ++ )
        {
            sum += vis[j][i];
            if ( sum != m ) return false;
        }
    }
    return true;
}

void search(int cur, int x, int y)
{
    if ( cur == m * n ) 
    {
        printf("hello");
        if (check()) ans ++;
    }
    else
    {
        if ( y == n  )
        {
            search(cur, x + 1, 0);
        }
        else
        {
            for ( int i = 1; i < n; i ++ )
            {
                vis[x][y + i] = 1;
                search(cur + 1, x, y + i);
                vis[x][y + i] = 0;    
            }
            
        }
        
        
    }
}

int main()
{
    n = 4, m = 1;
    search(0,0,0);
    printf("%d\n",ans);
    return 0;
}
