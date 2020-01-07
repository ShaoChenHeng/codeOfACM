#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int T, n;
char ss[10010];


int main()
{
    scanf("%d",&T);
    while ( T --  )
    {
        scanf("%d",&n);
        scanf("%s",ss);
        int cntz = 0, cnty = 0, cnth = 0;
        for ( int i = 0; i < n; i ++ ) 
        {
            if ( ss[i] == 'z' ) cntz ++;
            else if ( ss[i] == 'y' ) cnty += cntz;
            else if ( ss[i] == 'h' ) cnth += cnty;
        }
        printf("%d\n",cnth);
    }
    return 0;
}
