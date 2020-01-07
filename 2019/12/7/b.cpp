#include <bits/stdc++.h>

using namespace std;

char ch1[2];
char ch2[1];

int main()
{
    scanf("%s",ch1);
    getchar();
    scanf("%c",&ch2[0]);
    if ( ch2[0] == 'B' )
    {
        if ( ch1[0] == 'J' || ch1[1] == 'J' ) printf("pmznb\n");
        else if ( ch1[0] == 'B' || ch1[1] == 'B' ) printf("lyrnb\n");
        else if ( ch1[0] == 'S' || ch1[1] == 'S' ) printf("ljrnb\n");
    }
    else if ( ch2[0] == 'S' )
    {
        if ( ch1[0] == 'B' || ch1[1] == 'B' ) printf("pmznb\n");
        else if ( ch1[0] == 'S' || ch1[1] == 'S' ) printf("lyrnb\n");
        else if ( ch1[0] == 'J' || ch1[1] == 'J' ) printf("ljrnb\n");
    }
    else if ( ch2[0] == 'J' )
    {
        if ( ch1[0] == 'S' || ch1[1] == 'S' ) printf("pmznb\n");
        else if ( ch1[0] == 'J' || ch1[1] == 'J' ) printf("lyrnb\n");
        else if ( ch1[0] == 'B' || ch1[1] == 'B' ) printf("ljrnb\n");
    }

    return 0;
}

