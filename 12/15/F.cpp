#include <bits/stdc++.h>
#define INF 10000
using namespace std;

int T,n;
char ch[100];

int get_ans( int n, int num )
{
    int endN, flag, ans = 0;
    n --;
    if ( n % 2 ) flag = 1; //奇数
    else flag = 2; //偶数
    
    if ( flag == 1 )
    {
        while ( num > 0 )
        {
            int tmp = num - 1;
            int check1 = 1, check2 = 1;
            //cout<<bitset<32>(tmp)<<endl;
            for ( int j = 0, i = n - 1; j <= i; j += 2, i -= 2 )
            {
                if ( (!( tmp & ( 1 << j ) )) != ( ! (tmp & ( 1 << i ) ) )) 
                {
                    check1 = 0;
                    break;
                }
            }
            for ( int j = 1, i = n; j <= i; j += 2, i -= 2 )
            {
                if ( (! ( tmp & ( 1 << j ) )) !=  (! ( tmp & ( 1 << i ) ) ) )
                {
                    
                    check2 = 0;
                    break;
                }
            }

            if ( check1 == 1 || check2 == 1 ) 
            {
                ans ++;

            }
           
            num --;
        }
    }
    else if ( flag == 2 )
    {
        while ( num > 0 )
        {
            int tmp = num - 1;
            int check1 = 1, check2 = 1;
            for ( int j = 0, i = n; j <= i ; j += 2, i -= 2 )
            {
                if ( ( !(tmp & ( 1 << j )) ) != ( !(tmp & ( 1 << i ) ) ) )
                {
                    check1 = 0;
                    break;
                }
            }
            for ( int j = 1, i = n - 1; j <= i ; j += 2, i -= 2 )
            {
                if ( (!(tmp & ( 1 << j ) ))!= ( !(tmp & ( 1 << i ) ) )) 
                {
                    check2 = 0;
                    break;
                }
            }
            if ( check1  || check2  ) ans ++;
            num --;
        }

    }
    
    return ans;
}

int main()
{
    scanf("%d",&T);
    while ( T -- )
    {
        int ans = 0;
        scanf("%d",&n);
        scanf("%s",ch);
        getchar();
        int num = 0, beg = n - 1;
        int beg_zero = INF, end_zero = INF, conti = 0;
        for ( int i = 0; i < n; i ++ )
        {
            num += (pow (2 , beg) * (ch[i] - '0'));
            beg --;
        }

        ans = get_ans(n,num);


        printf("%d\n",ans);

    }
    return 0;
}
