#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;

int main()
{
    int ntest;
    scanf("%d",&ntest);
    while ( ntest -- )
    {
        int n;
        cin >> n;
        vector<int> p(n+1);
        for ( int i = 1; i <= n; i++ ) cin >> p[i];
        vector<int> appear( n + 1 ), ans( n + 1 );
        for ( int i = 1; i <= n; i++ )
        {
            if ( !appear[i] )
            {
                int cnt = 0, j = i;
                do
                {
                    appear[j] = i;
                    j = p[j];
                    ++cnt;
                } while ( j != i );
                ans[i] = cnt;
            }
        }
        for ( int i = 1; i <= n; i++ ) printf("%d ",ans[appear[i]]);
        printf("\n");
    }
    return 0;
}
