#include <cstdio>

using namespace std;

int n;

int main()
{
    int a[12];
    /* while( scanf("%d",&n) != EOF)
    { */
        scanf("%d",&n);
        while( n-- )
        {
            for ( int i = 1; i <= 11; i ++ ) scanf("%d",&a[i]);
            printf("%d",6);
            for ( int i = 1; i <= 11; i ++ ) printf("%d",a[i]);
            
            //for ( int i = 6; i <= 11; i ++ ) printf("%d",a[i]);
            printf("\n");
        }
        
    //}
    return 0;
}
