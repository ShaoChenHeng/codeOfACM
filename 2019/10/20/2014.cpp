#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;

int main()
{
    while(scanf("%d",&n) != EOF && n)
    {
        int minus = 0;
        int plus = 0;
        int zero = 0;
        int num;
        for ( int i = 0; i < n; i++ ) 
        {
            scanf("%d",&num);
            if ( num > 0 ) plus ++;
            else if ( num < 0 ) minus ++;
            else zero ++;
            printf("%d %d %d\n",minus, plus, zero);
        }
    }
    return 0;
}
