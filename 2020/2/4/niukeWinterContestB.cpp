#include <bits/stdc++.h>

using namespace std;

int n, x, a,b;

int main()
{
    scanf("%d %d %d %d",&n, &x, &a, &b);
    int perfect = n * a;
    int great = n * b;
    double per1 = x, per2 = 100 - x;
    double ans;
    ans = per1 * 0.01 * perfect + per2 * 0.01 * great;
    printf("%.2lf", ans);

    return 0;
}
