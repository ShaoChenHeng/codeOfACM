#include<bits/stdc++.h>

using namespace std;

int a,b,x,n,q;

int main()
{
    scanf("%d",&q);
    while ( q-- )
    {
        scanf("%d %d %d %d",&n,&x,&a,&b);
        printf("%d\n", min(n - 1, abs(a - b) + x));
    }
    return 0;
}
