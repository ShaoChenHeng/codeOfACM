#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[150010];
int ans;
stack<int> s;

void calc()
{
    int item;
    s.push(a[1]);
    //item = s.top();
    for ( int i = 2; i <= n; i ++ )
    {
        item = s.top();
        while ( a[i] < item && !s.empty() )
        {   
            s.pop();
            ans ++;
            if ( s.empty() ) break;
            item = s.top();
        }
        //printf("hello\n");
        s.push(a[i]);
    }
}

int main()
{
    scanf("%d",&t);
    while ( t -- )
    {
        while ( !s.empty() ) s.pop();
        scanf("%d", &n);
        ans = 0;
        for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
        calc();
        printf("%d\n", ans);
    }
    return 0;
}
