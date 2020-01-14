#include <bits/stdc++.h>

using namespace std;

int n;
int arr1[2000010], arr2[2000010], arr3[2000010];

int main()
{

    scanf("%d", &n);
    for ( int i = 1, j = n; i <= n; i ++, j -- )
    {
        scanf("%d", &arr1[i]);
        arr2[j] = arr1[i];
    }
    for ( int i = 1, j = n; i <= j; i ++, j -- )
    {
        if ( i % 2 == 0 )
        {
            arr3[i] = arr1[i];
            arr3[j] = arr1[j];
        }
        else
        {
            arr3[i] = arr2[i];
            arr3[j] = arr2[j];
        }
    }
    for ( int i = 1; i <= n; i ++ ) printf("%d ",arr3[i]);
    printf("\n");
}
