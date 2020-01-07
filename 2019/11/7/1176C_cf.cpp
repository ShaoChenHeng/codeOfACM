#include<bits/stdc++.h>

using namespace std;

int m;
int n;
int a[500010];
int cnt[7];

void swap()
{
    if ( n == 4 ) n = 1;
    else if ( n == 8 ) n = 2;
    else if ( n == 15 ) n = 3;
    else if ( n == 16 ) n = 4;
    else if ( n == 23 ) n = 5;
    else if ( n == 42 ) n = 6;
}

int main()
{
    scanf("%d",&m);
    memset(cnt, 0, sizeof(cnt));
    for ( int i = 1; i <= m; i ++ ) 
    {
        scanf("%d",&n);
        swap();
        a[i] = n;
    }
    for ( int i = 1; i <= m; i ++)
    {
        if ( a[i] == 1 ) cnt[1] ++;
        else
        {
            if ( cnt[a[i] - 1] )
            {
                cnt[a[i]] ++;
                cnt[a[i]-1] --;
            }
        }
        
    }
    printf("%d",m - cnt[6] * 6);

    return 0;
}

