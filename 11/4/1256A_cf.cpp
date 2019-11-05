#include<bits/stdc++.h>
using namespace std;
int T;
int a,b,n,s;
int main() 
{
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d%d%d%d",&a,&b,&n,&s);
        int num = s / n;
        num = min(num, a);
        if( num * n + b >= s ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
