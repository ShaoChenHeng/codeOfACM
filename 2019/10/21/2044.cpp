#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long a[10000] = {0,1,2,3};

int main()
{
    int ar,br;
    for( int i = 4; i < 51; i ++ ) a[i] = a[i-1] + a[i-2];
    while(scanf("%d",&n) != EOF)
    {

        while( n -- )
        {
            scanf("%d %d",&ar,&br);
            printf("%lld\n",a[br-ar]);
        }
    }
    return 0;
}
