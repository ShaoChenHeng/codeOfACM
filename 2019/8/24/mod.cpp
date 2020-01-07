#include <cstdio>
using namespace std;

int n;

int main()
{
    while( scanf("%d",&n) != EOF )
    {
        int num;
        int cnt;
        while( n-- )
        {
            scanf("%d",&cnt);
            num = cnt;
            for ( int i = 1; i < cnt; i ++ ) num *= cnt; 
            printf("%d\n",num%10);
        }
    }
    return 0;
}
