#include<bits/stdc++.h>
using namespace std;
int a[50];

int main()
{
    a[0]=0,a[1]=1;
    for(int i=2; i<50; i++) a[i]=a[i-1]+a[i-2];
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        /* cin>>m;
        cout<<a[m]<<endl; */
        scanf("%d",&m);
        printf("%d\n",a[m]);
    }
}
