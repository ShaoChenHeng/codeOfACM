#include<bits/stdc++.h>
using namespace std;
const int N = 31000;
const int M = 110000;
int n,m;
int dis[N];
bool vis[N];
int head[N],num;
struct Edge{
    int to,next,w;
}s[M];
void add(int u,int v,int w)//根据公式建边
{
    s[++num].w=w;
    s[num].next=head[u];
    head[u]=num;
    s[num].to=v;
}
void spfa(int x)//SPFA经典操（ban）作（zi）
{
    queue<int> q;
    q.push(x);
    for(int i=0;i<=n+1;i++)
        dis[i]=1;
    dis[x]=0;vis[x]=1;
    while(!q.empty())
    {
        int g=q.front();
        q.pop();
        vis[g]=0;
        for(int i=head[g];i!=-1;i=s[i].next)
        {
            int t=s[i].to;
            if(dis[t]>dis[g]+s[i].w)
            {
                dis[t]=dis[g]+s[i].w;
                if(!vis[t])
                {
                    q.push(t);
                    vis[t]=1;               
                }
            }
        }
    }
}
int main()
{
    int a,b,c,minn=123456789;
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    int y=n+1;
    for(int i=0;i<=n;i++) add(y,i,0);
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        add(b,a-1,-c);
    }
    for(int i=1;i<=n;i++)//建边操作
    {
        add(i-1,i,1);
        add(i,i-1,0);
    }
    spfa(y);
    for(int i=0;i<=n;i++)//取最小值
        minn=min(minn,dis[i]);
    cout<<dis[n]-minn<<endl;
    return 0;
}
