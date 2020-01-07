#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    double r1, a1, r2, a2;
    while ( n-- )
    {
        double ans = 0;
        scanf("%lf %lf %lf %lf",&r1, &a1, &r2, &a2);
        if ( r1 < r2 )
        {
            if ( a1 > a2 )
            {
                double rest_a = a1 - a2;
                ans = acos(-1.0) * r1 * r1 * ( rest_a / 360 );
            }
            else if ( a1 < a2 || a1 == a2) ans = 0;
            
        }
        else if ( r1 > r2 )
        {
            if ( a1 > a2 ) ans = acos(-1.0) * r1 * r1 * a1 / 360 - acos(-1) * r2 * r2 * a2 / 360;
            
            else if ( a1 < a2 || a1 == a2 ) ans = acos(-1.0) * r1 * r1 * a1 / 360 - acos(-1) * r2 * r2 * a1 / 360;
        }
        else
        {
            if ( a1 > a2 )
            {
                double rest_a = a1 - a2;
                ans = acos(-1.0) * r1 * r1 * ( rest_a / 360 );
            }
            else if ( a1 < a2 || a1 == a2 ) ans = 0;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
