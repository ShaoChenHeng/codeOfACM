#include <bits/stdc++.h>

using namespace std;

int n;
map< int, int > m;
int cnt[100010];

int main()
{
    scanf("%d",&n);
    int num, i;
    for (  i = 1; i <= n - 1; i ++ )
    {
        scanf("%d",&num);
        cnt[num] = 1;
    }
    for (  i = 1; i <= n; i ++ )
    {
        if ( cnt[i] == 0 )
        {
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}
