#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100];

int main()
{
    scanf("%d %d",&n, &m);
    for ( int i = 0; i < m; i ++ ) scanf("%d", &a[i]);
    sort(a, a + m);
    int ret = 1000000;
    for(int i = 0 + n - 1; i < m; ++i) ret = min(ret,a[i] - a[i-n+1]);
    printf("%d\n",ret);
    return 0;
}
