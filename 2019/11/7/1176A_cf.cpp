#include<bits/stdc++.h>

using namespace std;

int q;

int main()
{
    long long int num,ans = 0;
    scanf("%d",&q);
    while ( q-- )
    {
        ans = 0;
        scanf("%lld",&num);
        while ( !(num % 2) ) {num /= 2; ans ++;}
        while ( !(num % 3) ) {num /= 3; ans += 2;}
        while ( !(num % 5) ) {num /= 5; ans += 3;}
        if ( num != 1 ) printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}

