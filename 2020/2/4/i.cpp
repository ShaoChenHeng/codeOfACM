#include <bits/stdc++.h>

using namespace std;

//string str.substr(nStart)                 
//默认 从str字符串nStart位置开始截取到str结束为止

//string str.substr(nStart, nLength)  
// 从str字符串nStart位置开始截取nLength个字符！
//如果nLength>剩余的字符则截取到str结束为止

long long int dp[330000];
long long int n, a, b, c;
string ss;

int main()
{
    scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
    cin >> ss;
    //long long int ans = 0;
    for ( int i = 3; i < n; i ++ )
    {
        dp[i] = dp[i - 1];
        long long int temp;
        if ( ss.substr(i - 3, 4) == "nico" )
        {
            if ( i == 3 ) temp = dp[i - 3];
            else temp = dp[i - 4];
            dp[i] = max( dp[i], temp + a);
        }
        if ( i >= 5 && ss.substr( i - 5, 6 ) == "niconi"  )
        {
            if ( i == 5 ) temp = dp[i - 5];
            else temp = dp[i - 6];
            dp[i] = max( dp[i], temp + b );
        }
        if ( i >= 9 && ss.substr( i - 9, 10 ) == "niconiconi" )
        {
            if ( i == 9 ) temp = dp[i - 9];
            else temp = dp[i - 10];
            dp[i] = max( dp[i], temp + c );
        }
    }
    printf("%lld\n",dp[n - 1]);

    return 0;
}
