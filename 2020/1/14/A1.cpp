#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

int n, m;
set<int> arr1;
set<int> arr2;
set<int> arr3;

int main()
{
    int n;
    scanf("%d %d", &n, &m);
    int num1;
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d", &num1);
        arr1.insert(num1);
    }
    for ( int i = 1; i <= m; i ++ )
    {
        scanf("%d", &num1);
        arr2.insert(num1);
    }
    set_intersection( ALL(arr1), ALL(arr2), INS(arr3) );
    if ( arr3.size() >= 1 ) cout<<*arr3.begin()<<endl;
    else
    {
        cout << min(*arr1.begin(),*arr2.begin())*10 + max(*arr1.begin(),*arr2.begin());
    }
    
    return 0;
}
