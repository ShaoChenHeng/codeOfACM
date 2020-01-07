#include<cstdio>
#include<cstring>
using namespace std;

int t,n,a[150010],b[150010],c[150010];

int min(int a,int b)
{
    return a<b?a:b; 
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        int ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int minn=2147483647;
        for(int i=n;i;i--){
            if ( a[i] > minn ) ans++;
            minn = min(minn, a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
