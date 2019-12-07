#include <bits/stdc++.h>

using namespace std;

char ss[200];
int q;

int main()
{
    scanf("%d",&q);
    while ( q-- )
    {
        int cnt_y = 0, cnt_n = 0;
        scanf("%s",ss);
        int _len = strlen(ss);
        int total = _len / 2;
        for ( int i = 0; i < _len; i ++ )
        {
            if ( ss[i] == 'y' || ss[i] == 'Y' )
            {
                cnt_y ++;
            }

            else if ( ss[i] == 'n' || ss[i] == 'N' )
            {
                cnt_n ++;
            }
        }
        if ( cnt_y >= total ) printf("pmznb\n");
        else if ( cnt_n >= total ) printf("lyrnb\n");
        else printf("wsdd\n");
        }

    return 0;
}
