#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int res[120][120];

struct node
{
    int score, id;
    bool operator < (struct node a)
    {
        return score > a.score;
    }
} a[120];

int main()
{
    int T, n;
    scanf("%d", &T);
    while( T -- )
    {
        scanf("%d", &n);
        for( int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++) scanf("%d", &res[i][j]);
        }
        
        for(int i = 1; i <= n; i++)
        {
            a[i].id = i;
            a[i].score = 0;
            for(int j = 1; j <= n; j++)
            {
                if( i == j) continue;
                if ( res[i][j] > res[j][i] ) a[i].score += 3;
                else if( res[i][j] == res[j][i] ) a[i].score += 1;
            }
        }
        a[n+1].score = -1;
        sort( a + 1, a + 1 + n );
        if( a[1].score != a[2].score ) printf("%d\n", a[1].id);
        else printf("yep!\n");
    }
    
    return 0;
}
