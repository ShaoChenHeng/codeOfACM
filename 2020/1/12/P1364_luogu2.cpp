//P1364_luogu2
//floyd
#include <bits/stdc++.h>

using namespace std;

int G[110][110];
int arr[110];
int n;


int main()
{
    scanf("%d", &n);
    int a,b;
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j <= n; j ++ ) G[i][j] = 10000000;
    }
    for ( int i = 1; i <= n; i ++ )
    {
        G[i][i] = 0;
        scanf("%d %d %d", &arr[i], &a, &b);
        if ( a > 0 ) G[i][a] = 1, G[a][i] = 1;
        if ( b > 0 ) G[i][b] = 1, G[b][i] = 1;
    }
    for ( int k = 1; k <= n; k ++ )
    {
        for ( int i = 1; i <= n; i ++ )
        {
            if (i != k  )
            {
                for ( int j = 1; j <= n; j ++ )
                {
                    if ( i != j && j != k  )
                    {
                        G[i][j] = min( G[i][k] + G[k][j], G[i][j] );
                    }
                }
            }
        }
    }
    int _min = 0x7fffffff;
    int total;
    for ( int i = 1; i <= n; i ++ )
    {
        total = 0;
        for ( int j = 1; j <= n; j ++ )  
        {
            total += G[i][j] * arr[j];
            //printf("%d ", G[i][j]);
        }
        //printf("\n");
        _min = min(_min, total);
    }
    printf("%d\n", _min);
    return 0;
}
