#include <bits/stdc++.h>

using namespace std;

int q;
string ss;
int dir[5];

int main()
{
    scanf("%d",&q);
    while ( q-- )
    {
        int sum = 0;
        cin >> ss;
        memset(dir, 0, sizeof(dir));
        for ( int i = 0; i < ss.size(); i ++ )
        {
            if ( ss[i] == 'L' ) dir[0] ++;
            else if ( ss[i] == 'R' ) dir[1] ++;
            else if ( ss[i] == 'U' ) dir[2] ++;
            else if ( ss[i] == 'D' ) dir[3] ++;
        }
        /* if ( dir[0] % 2 ) dir[0] --;
        if ( dir[1] % 2 ) dir[1] --;
        if ( dir[2] % 2 ) dir[2] --;
        if ( dir[3] % 2 ) dir[3] --; */
        dir[0] = min(dir[0], dir[1]);
        dir[1] = min(dir[0], dir[1]);
        dir[2] = min(dir[2], dir[3]);
        dir[3] = min(dir[2], dir[3]);
        for ( int i = 0; i <= 3; i ++ ) sum += dir[i];
        if ( sum > 0 )
        {
            if ( dir[2] == 0 || dir[3] == 0 ) 
            {
                printf("2\n");
                printf("LR\n");
            }
            else if ( dir[0] == 0 || dir[1] == 0 ) 
            {
                printf("2\n");
                printf("UD\n");
            }
            else
            {
                printf("%d\n",sum);
                for ( int i = 1; i <= dir[1]; i ++ ) printf("R");
                for ( int i = 1; i <= dir[3]; i ++ ) printf("D");
                for ( int i = 1; i <= dir[0]; i ++ ) printf("L");
                for ( int i = 1; i <= dir[2]; i ++ ) printf("U");
                printf("\n");
            }
        }
        else printf("0\n\n");
        
        //printf("%d",ss.size());
        //cout << ss.size()<<endl;

    }
    

    return 0;
}
