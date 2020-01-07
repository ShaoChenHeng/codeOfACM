#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    /* for ( int i = 0; i < N; i ++ )
        printf("%f ",A[i]); */
    printf("%.2f\n", Median(A, N));

    return 0;
}

#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(ElementType *)a-*(ElementType *)b;//这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}

/* void qsort(ElementType a[], int l,int r)
{
    int mid = a [ ( l + r ) / 2 ]; 
    int i=l,j=r;
    ElementType temp;
    do{
        while( a[i] < mid ) i++;
        while( a[j] > mid ) j--;
        if( i <= j )
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while( i <= j );
    if( l < j ) qsort( a, l, j);
    if( i < r ) qsort( a, i, r);
} */

ElementType Median( ElementType A[], int N )
{
    qsort(A, N , sizeof(A[0]),cmp);
    return A[N/2];
}
