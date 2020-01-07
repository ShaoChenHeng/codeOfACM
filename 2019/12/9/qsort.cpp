#include <bits/stdc++.h>

using namespace std;



void qsort(int a[], int l,int r)
{
    int mid = a [ ( l + r ) / 2 ];
    int i=l,j=r;
    do{
        while( a[i] < mid ) i++;
        while( a[j] > mid ) j--;
        if( i <= j )
        {
            swap( a[i], a[j]);
            i++;
            j--;
        }
    } while( i <= j );
    if( l < j ) qsort( a, l, j);
    if( i < r ) qsort( a, i, r);
}
/* 
int Median( int A[], int N )
{
	if(N%2==1) 
		return A[N/2];			
	else
		return A[N/2-1];
}
 */

int main()
{
    int n;
    int a[100005];

    scanf("%d",&n);
    for ( int i = 0; i < n; i ++ ) scanf("%d",&a[i]);
    qsort(a,0,n-1);
    for ( int i = 0; i < n; i ++ ) printf("%d ",a[i]);
    printf("\n");

    return 0;
}
