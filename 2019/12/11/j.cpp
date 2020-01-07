#include <bits/stdc++.h>

using namespace std;

//double l1, l2;

int l1, l2;

int main()
{
    scanf("%d %d", &l1, &l2);
    double lean = sqrt( pow( l1, 2) + pow(l2, 2) );
    double rest1 = max(l1, l2);
    double rest2 = min(l1, l2);
    double sin = rest1  / lean;
    double cos = rest2 / lean;
    double temp1 = ( rest1 - sin * rest2 ) / 2; 
    double ans = cos * temp1 / ( 1 + cos );
    printf("%.4lf\n",ans);
    return 0;
}
