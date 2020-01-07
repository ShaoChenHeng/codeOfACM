#pragma GCC opertime(2)
#pragma GCC opertime(3)
#include<bits/stdc++.h>
using namespace std;
const int N=2750133;
int n,cnt,a[N],b[N],prim[N],vis[N],xu[N];
void work(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])prim[++cnt]=i;
        for(int j=1;j<=cnt;j++)
        {
            if(i*prim[j]>n)break;
            vis[i*prim[j]]=1;
            xu[i*prim[j]]=i;
            if(i%prim[j]==0)break;
        }
    }
}
bool cmp(int a,int b)
{
    if(vis[a]==0)
    {
        if(vis[b]==0)return a<b;
        else return 0;
    }
    if(vis[b]==0)
    {
        return 1;
    }
    return a > b;
}
int main()
{
    work(2750131);
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    sort(a+1,a+2*n+1,cmp);
    for ( int i = 1; i <= 2 * n; i ++ ) printf("%d ",a[i]);
    /* for(int i=1;i<=2*n;i++)
    {
        if(b[a[i]])
        {
            printf("%d ",a[i]);
            b[a[i]]--;
            if(vis[a[i]]==0&&a[i]<=cnt)b[prim[a[i]]]--;
            if(vis[a[i]])b[xu[a[i]]]--;
        }
    } */
    return 0;
}
