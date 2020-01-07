#include <bits/stdc++.h>

using namespace std;

int n, T;
int pos[200100];

struct stu
{
    int grade;
    int pos,rank;
} a[200100];

bool cmp( stu x, stu y )
{
    return x.grade > y.grade;
}

int main()
{
    scanf("%d",&T);
    while ( T-- )
    {
        memset(pos, 0, sizeof(pos));
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++  )
        {
            scanf("%d", &a[i].grade);
            a[i].pos = i;
        }
        sort(a + 1, a + n  +1, cmp);
        int reap = 1, now_rank = 1;
        a[1].rank = now_rank;
        for (int i = 2; i <= n; i ++  )
        {
            if ( a[i].grade == a[i-1].grade )
            { 
                reap ++;
                a[i].rank = now_rank;
            }
            else 
            {
                now_rank += reap;
                a[i].rank = now_rank;
                reap = 1;
            }
        }
        for ( int i = 1; i <= n; i++)
        {
            pos[a[i].pos] = a[i].rank;

        }
        for ( int i = 1; i <= n ; i ++ )
        {
            printf("%d",pos[i]);
            if ( i != n ) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
