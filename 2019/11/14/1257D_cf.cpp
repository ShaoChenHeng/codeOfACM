#include <bits/stdc++.h>

using namespace std;

struct hero
{
    int power, endurance;
} h[200010];

int t,n,m;
int  hero_vis[200010];
int monster[200010];

bool is_day_end()
{
    int cnt = 0;
    for ( int i = 1; i <= m; i++ ) if ( hero_vis[i] == -1 ) cnt ++;
    return cnt == m;
}

bool cmp( hero a, hero b )
{
    return a.power < b.power;
}

int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        int max_monster = -1, max_hero = -1;
        int  item;
        int cnt = 0, ans = 0;
        for ( int i = 1; i <= n; i++ ) 
        {
            scanf("%d",&item);
            monster[i] = item;
            max_monster = max( max_monster, item );
        }
        scanf("%d",&m);
        for ( int i = 1; i <= m; i ++ ) 
        {
            scanf("%d %d",&h[i].power, &h[i].endurance);
            max_hero = max( max_hero, h[i].power );
        }
        if ( max_monster > max_hero ) printf("-1\n");
        else
        {
            memset( hero_vis, 0, sizeof(hero_vis[0]) * ( m + 1 ) );
            int cur_monster;
            int is_defeat = 0, count = 0, pos = 1;
            sort( h + 1, h + m + 1, cmp );
            while ( pos != n )    
            {
                cur_monster = monster[pos];
                is_defeat = 0;
                if ( is_day_end() )
                {
                    count = 0;
                    ans ++;
                    memset( hero_vis, 0, sizeof( hero_vis[0]) * ( m + 1 ) );
                }
                //int i = lower_bound( h + 1, h + m + 1, cur_monster, cmp) - h;
                long long l = 1, r = m, mid, i;
                while ( l < r )
                {   
                    mid = ( l + r ) / 2;
                    if ( h[mid].power < cur_monster ) 
                    {
                        l = mid + 1;
                        i = l;
                    }
                    else
                    {
                        r = mid;
                        i = r;
                    }
                }
                for ( int j = 1; j < i; j ++ ) hero_vis[j] = -1;
                for ( ; i <= m; i++ )
                {
                    if ( h[i].power >= cur_monster && hero_vis[i] != -1)
                    {
                        if ( hero_vis[i] < h[i].endurance) 
                        {
                            hero_vis[i] ++;
                            is_defeat = 1;
                        }
                        else {hero_vis[i] = -1; }
                    }
                    else  {hero_vis[i] = -1;}
                }
                if ( is_defeat ) pos ++;
                
            }
            printf("%d\n",ans + 1);
        }
            
    }
    return 0;
}
