#include <cstdio>
#include <algorithm>

using namespace std;

int n,T;
int arr[110];

int main()
{
    while ( scanf("%d",&T) != EOF )
    {
        while( T -- )
        {
            int ans = 0;
            scanf("%d",&n);
            for ( int i = 0; i < n; i++ )      
            {
                scanf("%d",&arr[i]);
            }
            sort(arr,arr+n);
            for ( int i = 0; i < n - 1; i ++ )
            {
                if (arr[i+1] - arr[i] == 1 )  ans ++;
            }
            if ( ans ) printf("2\n");
            else printf("1\n");


        }
    }
    
    return 0;
}
