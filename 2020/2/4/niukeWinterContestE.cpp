#include <bits/stdc++.h>

using namespace std;

long long int n;

long long int _num( long long int n)
{ 
    long long int count = 2;
    for(long long int i = 2; i <= sqrt(n); i++)
    {
        if( n % i == 0 )
        {
            if( i == sqrt(n) && n/i==i)
            { 
                count++;   
            }
            else count += 2;
        }
    }
    return count;
}

int main()
{
    scanf("%lld", &n);
    long long int cnt = 0;
    long long int num = _num(n);
    cnt ++;
    while ( num != 2 )
    {
        num = _num(num);
        cnt ++;
    }
    printf("%lld\n",cnt);
    return 0;
}
