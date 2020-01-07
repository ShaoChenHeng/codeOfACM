#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int vis[N], prim[N], xu[N], cnt,n;
void work(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if ( !vis[i] ) prim[++cnt] = i;
        for ( int j = 1; j <= cnt; j++ )
        {
            if ( i * prim[j] > n ) break;
            vis[i*prim[j]] = 1;
            xu[i*prim[j]] = i;
            if( i % prim[j] == 0 )break;
        }
    }
}

int main()
{
    cnt = 0;
    scanf("%d",&n);
    work(n);
	for(int i = 0; i < n; i++)
	{
        if ( !vis[i] ) printf("%d ", i);
	}

}
