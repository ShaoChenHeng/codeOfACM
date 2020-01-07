#include<stdio.h>
#include<string.h>
int main()
{
    long long a[41],n,m;
    int i,q,b[41],flag;
    a[0]=0;
    a[1]=1;
    for(i=2;i<41;i++)
        a[i]=a[i-1]*3;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld",&n);
        m=n;
        memset(b,0,sizeof(b));
        flag=40;
        while(a[flag]>n) flag--;
        for(i=flag;i>0;i--)
            if(a[i]<=m)
            {
                b[i]=1;
                m-=a[i];
            }
        if(m==0) printf("%lld\n",n);
        else
        {
            i=1;
            while(b[i]) i++;
            if(i>flag) printf("%lld\n",a[i]);
            else
            {
                m=a[i];
                for(;i<=flag;i++)
                    if(b[i]) m += a[i];
                printf("%lld\n",m);
            }
        }
    }
    return 0;
}
