#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;
int a[MAXN];
int b[MAXN], L[MAXN], R[MAXN];
int n , l, r, k;


int main()
{
    scanf("%d %d %d %d",&n, &l, &r, &k);
    for ( int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    L[1] = l, R[1] = r;
    for ( int i = 2; i <= n; i++ )
    {
        if ( a[i] == a[i - 1] )
        {
            L[i] = L[i - 1];
            R[i] = R[i - 1];
        }
        else if ( a[i] > a[i - 1] )
        {
            L[i] = L[i - 1] + 1;
            R[i] = min( R[i - 1]  + k, r); 
        }
        else if ( a[i] < a[i - 1] )
        {
            L[i] = max( L[i - 1] - k, l );
            R[i] = R[i - 1] - 1;
        }
        if ( L[i] > R[i] || R[i] < l || L[i] > r )
        {
            printf("-1\n");
            return 0;
        }
    }
    b[1] = L[1];
    /* for ( int i = 1; i <= n; i++ ) printf("%d ",L[i]);
    printf("\n");
    for ( int i = 1; i <= n; i++ ) printf("%d ",R[i]);
    printf("\n"); */
    for ( int i = n - 1; i >= 1; i -- )
    {
        if ( a[i] == a[i + 1] ) b[i] = b[i+1];
        else if ( a[i] < a[i + 1] ) b[i] = max( b[i + 1] - k, L[i] );
        else if ( a[i] > a[i + 1] ) b[i] = max( b[i + 1] + 1, L[i] );
    }
    for ( int i = 1; i <= n; i++ ) printf("%d ",b[i]);
    printf("\n");

    return 0;
}
