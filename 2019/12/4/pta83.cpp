#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int num, _max = -1, _min = 10000000;
    double sum = 0;
    for ( int i = 1; i <= n; i ++ ) 
    {
        scanf("%d",&num);
        _max = max( _max, num );
        _min = min( _min, num );
        sum += num;
    }
    printf("average = %.2lf\n",sum / n);
    printf("max = %d.00\n", _max);
    printf("min = %d.00\n",_min);
    return 0;
}
