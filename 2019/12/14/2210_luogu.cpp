#include <bits/stdc++.h>

using namespace std;

int n;
int f[13][3], pos[13], best_ans = INT_MAX;


const double BeginT = 10000, EndT = 1e-17, ChangeT = 0.989;

int get_cost()
{
    int tmp_ans = 0;
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int j = 0; j < 3; j ++ ) tmp_ans += abs( pos[i] - pos[f[i][j]] );
    }
    return tmp_ans;
}

void SA( int times )
{
    int x, y, tmp_ans;
    while ( times -- )
    {
        for ( double T = BeginT; T > EndT; T *= ChangeT )
        {
            do
            {
                x = rand() % n + 1;
                y = rand() % n + 1;
            } while ( x == y );
            swap( pos[x], pos[y] );
            tmp_ans = get_cost();
            if ( tmp_ans <= best_ans ) best_ans = tmp_ans;
            else if ( exp( (best_ans - tmp_ans) / T ) > ( double )rand() / RAND_MAX ) swap(pos[x], pos[y]);
        }
    }

}

int main()
{
    srand(time(0));
    scanf("%d",&n);
    for ( int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j < 3; j ++  ) scanf("%d",&f[i][j]);
        pos[i] = i;
    }
    SA(300);
    printf("%d\n", best_ans / 2);
    return 0;
}
