#include <bits/stdc++.h>

using namespace std;

int T, n;
string ss;

int main()
{
    scanf("%d", &T);
    while ( T -- )
    {
        scanf("%d", &n);
        cin >> ss;
        int maxP = 0, flag = 0, countP = 0;
        for ( int i = 0; i < n; i ++ )
        {
            if ( ss[i] == 'A' )
            {
                maxP = max( maxP, countP );
                countP = 0;
                flag = 1;
            }
            else if ( ss[i] =='P' )
            {
                if ( flag ) countP ++;
            }
        }
        maxP = max( maxP, countP );
        printf("%d\n",maxP);
    }

    return 0;
}
