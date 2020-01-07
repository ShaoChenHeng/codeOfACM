#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a,b;

int main()
{
    while ( scanf("%d", &n) != EOF && n )
    {
        while ( n -- )
        {
            scanf( "%d %d",&a,&b );
            if ( !(a % b) ) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
