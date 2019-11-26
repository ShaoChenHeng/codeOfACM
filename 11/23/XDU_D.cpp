#include <bits/stdc++.h>
using namespace std;
long long cou;
long long i,t,n,k,s;
int vis[1000010];
int main()
{
    
    while(scanf("%lld %lld",&n,&k)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        for( i=1; i<=n; i++)
        {
            scanf("%lld",&t);    
            s += t;
            if( s >= k ) s = s % k;
            vis[s] ++;
        }
        for( int i = 0; i <= k; i ++ )
        {
            t = vis[i];
            if( t > 1 )
            {
                cou += t * ( t - 1 ) / 2;
            }
        }
        for (int i = 0; i < k; i++) printf("%d ",vis[i]);
        printf("\n");
        printf("%lld\n",cou);
    }
    return 0;
}
