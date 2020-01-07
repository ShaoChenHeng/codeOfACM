#include <iostream> 
 
using namespace std;
 
int n;
int a[3];
int b[3];

int main()
{
    while ( scanf("%d",&n) != EOF ) 
    {
        while ( n -- )
        {
            for ( int i = 0; i < 3; i ++ )scanf("%d",&a[i]);
            for ( int i = 0; i < 3; i ++ )scanf("%d",&b[i]);
            
            if ( (a[0] > b[0]) ||( a[0] == b[0] && a[1] > b[1]) || ( a[0] == b[0] && a[1] == b[1] && a[2] > b[2] )  ) printf("First\n");
            else if( a[0] == b[0] && a[1] == b[1] && a[2] == b[2] ) printf("Same\n");
            else printf("Second\n");
            
        }
    }
 return 0;
}
