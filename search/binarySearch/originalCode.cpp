#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];
vector<int> arr;

int binary_search(int l, int r, int key )
{
    int mid;
    while ( l < r )
    {
        mid = l + ( r - l ) / 2;
        if ( a[mid] < key  ) l = mid + 1;
        else if ( a[mid] > key ) r = mid - 1;
        else return mid;
    }
}

int my_upper_bound( int l, int r, int key )
{
    int mid;
    while ( l < r )
    {
        mid = l + ( r - l ) / 2;
        if ( a[mid] <= key  ) l = mid;
        else r = mid - 1;
        
    }
    return l;
}

int my_lower_bound( int l, int r, int key )
{
    int mid;
    while ( l < r )
    {
        mid = l + ( r - l ) / 2;
        if ( a[mid] < key  ) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main()
{
    scanf("%d", &n);
    int num;
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d", &num);
        arr.push_back(num);
        a[i] = num;
    }
    sort(a, a + n);
    sort(arr.begin(), arr.end());

    for ( int i = 0; i < n; i++ ) printf("%d ", a[i]);
    printf("\n");

    vector<int>::iterator ite;
    for ( ite = arr.begin(); ite != arr.end(); ite ++ ) cout << *ite <<' ';
    printf("\n");

    int pos = my_upper_bound( 0, n, 3 );
    printf("%d\n",pos);


    //printf("pos2 = %d\n",pos2);
    return 0;
}
