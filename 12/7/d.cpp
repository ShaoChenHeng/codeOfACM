#include <bits/stdc++.h>

using namespace std;

int n,m;
map<int, int> M;
long long int a[120];

int main()
{
    int type, l, r;
    scanf("%d %d",&n,&m);
    for ( int i = 1; i <= n; i ++ ) scanf("%lld",&a[i]);
    for ( int i = 1; i <= m ; i ++ )
    {
        scanf("%d %d %d",&type, &l, &r);
        if ( type == 1 )
        {
            for ( int i = l; i <= r; i ++ ) a[i] = a[i] * 251 % 996 * 404 * 123;
            
        }
        else if ( type == 2 )
        {
            M.clear();
            for ( int i = l; i <= r; i ++  )
            {
                M[a[i]] ++;
            }
            int _max = 0;
            map<int, int>::iterator ite;
            for ( ite = M.begin(); ite != M.end(); ite ++ )
            {
                if ( ite -> second > _max ) _max = ite -> second;
            }
            printf("%d\n",_max);
        }
    }

    return 0;
}
