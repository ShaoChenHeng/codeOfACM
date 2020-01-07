#include <cstdio>
#include <algorithm>

using namespace std;

int n,cnt;
int a[1100];

int main()
{
    while( scanf("%d",&n) != EOF  )
    {
        while( n-- )
        {
            scanf("%d",&cnt);
            for ( int i = 0; i < cnt ; i++ )
            {
                scanf( "%d",&a[i] );
            }
            sort(a,a+cnt);
            for( int i = 0; i < cnt; i++ )
            {
                printf( "%d ",a[i] );
            }
            printf("\n");
        }
        
    }

    return 0;
}
