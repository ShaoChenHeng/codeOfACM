#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int dp[10000];
int n,cnt,tmp;

int main()
{
    while( scanf("%d",&cnt) != EOF )
    {
        scanf("%d",&cnt);
        scanf("%d",&tmp);
        dp[0] = tmp;       
        for(int i=1; i < cnt; ++i) {
            // 状态转移方程 
            scanf("%d",&tmp);
            dp[i] = max(tmp, dp[i-1] + tmp);
        } 
        // 求最大连续子序列和 
        int k;
        k = dp[0];
        for(int i=1; i<cnt; ++i) {
            if(dp[i] > k) {
                k = dp[i];
            }
        }
        printf("%d",k);
    }
    return 0;
}
