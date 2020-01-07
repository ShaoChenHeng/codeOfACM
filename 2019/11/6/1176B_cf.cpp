#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[150],b[4];
vector<int> v;

int main() 
{
    scanf("%d",&T);
    while(T--) 
    {
        memset(b,0,sizeof(b));
        int ans = 0;
        scanf("%d",&n);
        for ( int i = 0; i < n; i++ ) 
        {
            scanf("%d",&a[i]);
            b[a[i]%3] ++;
        }
        int min3 = min( b[2], b[1]);
        b[1] -= min3;
        b[2] -= min3;
        ans = b[1] / 3 + b[2] / 3 + min3 + b[0];
        printf("%d\n",ans);

    }
    return 0;
}
