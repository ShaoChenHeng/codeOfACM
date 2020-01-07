#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;
void qsort(int q,int p,int w[])
{
    int l=q,r=p,mid=w[(q+p)/2],t;
    while(l<=r)
    {
        while(w[l]<mid)l++;
        while(w[r]>mid)r--;
        if(l<=r)
        {
            t=w[l];
            w[l]=w[r];
            w[r]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p,w);
    if(r>q) qsort(q,r,w);
}


int main()
{
    int n,m,k,i,day[2010],sum[2010];
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++) scanf("%d",&day[i]);
    if( k == n ) printf("%d\n",k);
    else
    {
        for(int i=1;i<n;i++)
            sum[i-1]=day[i]-day[i-1]-1;
        qsort(0,n-2,sum);
        int x=n-k;
        for(i=0;i<x;i++)
        {
            n += sum[i];
        }
        printf("%d\n",n);
    }
}
