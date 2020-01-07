#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q,_max = -1,num;
    scanf("%d",&q);
    while ( q-- )
    {
        _max = -1;
        scanf("%d",&n);
        for ( int i = 0; i < n; i ++ )
        {
            scanf("%d",&num);
            _max = max( num, _max );
        }
        printf("%d\n",_max);
    }
    return 0;
}
