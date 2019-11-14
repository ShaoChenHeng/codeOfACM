#include<bits/stdc++.h>

using namespace std;

int q;
int x,y;
// y >= 4一定有解
int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        scanf("%d %d",&x,&y);
        int flag = 0;
        if ( x >= 4 ) flag = 1;
        else
        {
            if ( x == 1 && y == 1 ) flag = 1;
            else if ( x <= 3 && 1 <  x && y <= 3  ) flag = 1;
        }
        if ( flag ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
