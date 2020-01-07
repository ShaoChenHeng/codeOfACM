#include<bits/stdc++.h>

using namespace std;

int n,b,a;
int way[200010];

int main()
{
    scanf("%d %d %d",&n,&a,&b);
    int curb = b, cura = a;
    int i;
    for (  i = 0; i < n ; i++ ) scanf("%d",&way[i]);
    for (  i = 0; i < n; i++ )
    {
        //printf("cura = %d curb = %d way[%d] = %d\n",cura,curb,i,way[i]);
        if ( way[i] == 0 )
        {
            if ( curb ) curb --;
            else if (cura) cura --;
            else break;
        }
        else
        {
            if ( cura && curb < b)
            {
                curb ++;
                cura --;
                curb = min( curb, b );
                //printf("hello\n");
            }
            else if ( curb ) curb --;
            else break;
        }
    }
    printf("%d\n", i);

    return 0;
}

