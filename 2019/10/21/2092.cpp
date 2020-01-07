#include<bits/stdc++.h>
using namespace std;
char s[100];
#define max1 1e-7
int main()
{
    int a,b;double c,d;
    while( scanf("%d%d",&a,&b) && a+b )
    {
        if( (int)( a+sqrt(a*a-4*b) ) / 2 == ( a+sqrt(a*a-4*b) ) / 2 )
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
