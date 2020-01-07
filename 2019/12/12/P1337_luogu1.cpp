#include <bits/stdc++.h>
#define down 0.996

using namespace std;

int n, sx, sy;
double ansx, ansy, answ;
double ans = 1e18, t;
const double delta = 0.993;

struct object
{
    int x, y, w;

} a[1010];

double energy( double x, double y )
{   
    double r = 0, dx, dy;
    for ( int i = 0; i < n; i ++ )
    {
        dx = x - a[i].x;
        dy = y - a[i].y;
        r += sqrt( dx * dx + dy * dy ) * a[i].w;
    }
    return r;
}

void sa()
{
    double t = 3000;
    while ( t > 1e-15 )
    {
        double ex = ansx + ( rand() * 2 - RAND_MAX ) * t;
        double ey = ansy + ( rand() * 2 - RAND_MAX ) * t;
        double ew = energy( ex, ey );
        double de = ew - answ;
        if ( de < 0 )
        {
            ansx = ex;
            ansy = ey;
            answ = ew;
        }
        else if ( exp( -de / t ) * RAND_MAX > rand() )
        {
            ansx = ex;
            ansy = ey;
        }
        t *= down;
    }
}

void solve()
{
    sa();
    sa();
    sa();
    sa();
}


int main()
{
    scanf("%d",&n);

    for ( int i = 0; i < n; i ++ )
    {
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].w);
        ansx += a[i].x;
        ansy += a[i].y;
    }
    ansx /= n;
    ansy /= n;
    answ = energy( ansx, ansy );
    solve();
    printf("%.3lf %.3lf", ansx, ansy);

    return 0;
}
