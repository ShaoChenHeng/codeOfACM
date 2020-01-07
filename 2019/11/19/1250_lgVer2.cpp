#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 30101;
const int MAXM = 100101;
int cnt=0,u[MAXM],v[MAXM],w[MAXM],first[MAXN],_next[MAXM];
bool vis[MAXN];
int inq[MAXN],dis[MAXN];
int n,h;
void addedge(int ux,int vx,int wx){
    ++cnt;
    u[cnt]=ux;
    v[cnt]=vx;
    w[cnt]=wx;
    _next[cnt]=first[ux];
    first[ux]=cnt;
}
int spfa(int s,int t){
    queue<int> q;
    for(int i=0;i<=n+1;i++){
        dis[i]=0x3f3f3f3f;
        }
    q.push(s);
    dis[s]=0;
    inq[s]=1;
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=first[u];i;i=_next[i]){
            if(w[i]+dis[u]<dis[v[i]]){
                dis[v[i]]=w[i]+dis[u];
                if(!vis[v[i]]){
                    vis[v[i]]=1;
                    inq[v[i]]++;
                    q.push(v[i]);
                    if(inq[v[i]]>n)
                        return 0x3f3f3f3f;
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&h);
    int b,e,t;
    for(int i=1;i<=h;i++){
        scanf("%d %d %d",&b,&e,&t);
        addedge(e,b-1,-t);
    }
    addedge(n+1,0,0);
    for(int i=1;i<=n;i++){
        addedge(n+1,i,0);
        addedge(i,i-1,0);
        addedge(i-1,i,1);
    }
    spfa(n+1,0);
    int mind=0x3f3f3f3f;
    for(int i=0;i<=n;i++){
        mind=min(mind,dis[i]);    
    }
    for ( int i = 0; i < 10; i ++ ) printf("%d ",dis[i]);
    printf("\n");
    printf("%d",dis[n]-mind);
    return 0;
}
