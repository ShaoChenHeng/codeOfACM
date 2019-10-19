#include <cstdio>
using namespace std;

int main()
{
    int n,cur1,cur2,sum;
    while( scanf("%d",&n) != EOF && n != 0 )
    {
        cur1 = 0;
        int res = 5 * n;
        sum = 0;
        sum += res;
        for ( int i = 0; i < n; i ++  )
        {
            scanf("%d",&cur2);
            if ( cur2 > cur1 ) sum += ( cur2 - cur1 ) * 6;
            else sum += ( cur1 - cur2 ) * 4;
            cur1 = cur2;
        }
        printf("%d\n",sum); 
    }
    return 0;
}


//It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor.
// The elevator will stay for 5 seconds at each stop.
