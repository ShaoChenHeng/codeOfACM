#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
int n;

int main()
{
    int num, _max = 0, t;
    scanf("%d",&n);
    for ( int i = 1; i <= 2 * n; i ++ )
    {
        scanf("%d", &num);
        if ( !m.count(num) ) m[num] = 1;
        else
        {
            m.erase(num);
        }
        t = m.size();
        _max = max( _max, t);
    }
    printf("%d\n",_max);
    return 0;
}
