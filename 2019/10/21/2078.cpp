#include<iostream>
#include<algorithm>
#include <cstdio>
using namespace std;

int t;

int main()
{
    while(scanf("%d",&t) != EOF)
    {
        int i,n,m;
        for(i=0;i<t;i++)
        {
        	scanf("%d %d",&n, &m);
            int j,a[50];
            for( j = 0; j < n; j++) scanf("%d",&a[j]);
            sort(a,a+n);
        	printf("%d\n",( 100 - a[0] ) * ( 100 - a[0] ) );
            //cout<<(100-a[0])*(100-a[0])<<endl;
        }
    }
    return 0;
}