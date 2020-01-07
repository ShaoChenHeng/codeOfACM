#include<cctype>
#include<cstdio>
#define R register
int T,N,A[200005],M,P,S,k,hur[200005],ans,am,pm,l,r,mid;
template<class T>inline void read(R T &m)
{
    m=0;
    R char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))m=(m<<3)+(m<<1)+(c&15),c=getchar();
}
inline bool check(R int kill)
{
    for(R int i=k; i<=k+kill-1; ++i)
    {
        if(A[i]>hur[kill])//有一个怪的血量超过了连续杀kill个怪能承受的最大血量
        {
            return 0;//不行
        }
    }
    return 1;
}
int main()
{
    read(T);
    while(T--)
    {
        read(N);
        k=1,ans=am=pm=0;
        for(R int i=1; i<=N; ++i)
        {
            hur[i]=0,
            read(A[i]),
            am=A[i]>am?A[i]:am;
        }
        read(M);
        for(R int i=1,tmp; i<=M; ++i)
        {
            read(P),read(S),
            pm=P>pm?P:pm,
            hur[S]=P>hur[S]?P:hur[S];
        }
        if(am>pm)//怪最大血量>最大承受量
        {
            puts("-1");
            continue;
        }
        for(R int i=N,mx=0; i; --i)
        {
            if(mx<hur[i])mx=hur[i];
            hur[i]=mx;
        }
        while(k<=N)
        {
            l=1,r=N-k+1;
            while(l<r)
            {
                mid=(l+r>>1)+1;
                if(check(mid))
                {
                    l=mid;
                }
                else
                {
                    r=mid-1;
                }
            }
            k+=l;//加上这一天的杀怪数
            ++ans;
        }
        printf("%d\n",ans);
    }
}
