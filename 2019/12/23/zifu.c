#include <stdio.h>
#include <string.h>

char s[50][50];
int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void dfs(int x, int y)
{
    s[x][y] = '*';
    int dx, dy;
    for(int i = 0; i < 4; i++)
    {
        dx = x + move[i][0];
        dy = y + move[i][1];
        if( dx < 0 || dx > 49 || dy < 0 || dy > 49) continue;
        if(s[dx][dy]=='*') continue;
        dfs(dx, dy);
    }
}

int main()
{
    
    int time = 0, n;
    while(gets(s[1]) != NULL)
    {
        time = 0;
        if(strlen(s[1]) == 0) continue;
        n = 1;
        for(int i = 2; ; i++)
        {
            gets(s[i]);
            if( strlen(s[i]) == 0 ) break;
            n++;
        }
        
        for(int i = 0; i <= 49; i++)
        {
            for(int j = 0; j <= 49; j++)
            {
                if(s[i][j]!='*') 
                {
                    dfs(i, j);
                    time++;
                }
            }
        }
             
        if ( time == 1 ) printf("C\n");
        else if ( time == 2 ) printf("A\n");
        else printf("B\n");
        memset(s, 0, sizeof(s));
    }
    return 0;
}
