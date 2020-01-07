#include <bits/stdc++.h>

using namespace std;


int n, a[1010];
int best_ans = INT_MAX;
int vis[1010];

/* inline int get_ans()
{
    int  sum1 = 0, sum2 = 0;
    vector<int>::iterator ite;
    for ( ite = que1.begin(); ite != que1.end(); ite ++ )  sum1 += *ite;
    for ( ite = que2.begin(); ite != que2.end(); ite ++ ) sum2 += *ite;
    que1.clear();
    que2.clear();
    //printf("sum1 = %d sum2 = %d\n",sum1, sum2);
    return abs(sum1 - sum2);
}
 */
const double BeginT = 2000, EndT = 1e-12, ChangeT = 0.99;

inline void SA( int times )
{
    int x = rand() % n + 1, y = rand() % n + 1;
    int tmp_ans, count = 0;
    int sum1 = 0, sum2 = 0;
    while ( times -- )
    {
        for ( double T = BeginT; T > EndT; T *= ChangeT )
        {
            memset(vis,0,sizeof(vis));
            count = 0, sum1 = 0, sum2 = 0;
            while ( count < n )
            {
                while ( vis[x] ) x =rand() % n + 1 ;
                vis[x] = 1;
                while ( vis[y] ) y = rand() % n + 1;
                vis[y] = 1;
                sum1 += a[x];
                sum2 += a[y];
                count += 2;
            }

            tmp_ans = abs(sum1 - sum2);
            if ( tmp_ans <= best_ans ) best_ans = tmp_ans;
            else if ( exp( (best_ans - tmp_ans) / T ) > ( double )rand() / RAND_MAX ) best_ans = tmp_ans;
            
        }
    }
}

int main()
{
    srand(10000007);
    scanf("%d",&n);
    for ( int i = 1; i <= n; i ++ ) scanf("%d",&a[i]);
    SA(2);
    printf("%d\n",best_ans);
    return 0;
}
