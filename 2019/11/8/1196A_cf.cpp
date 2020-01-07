#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int q;
ll sum,num1,num2,num3;

int main()
{
    scanf("%d",&q);
    while ( q -- )
    {
        sum = 0;
        scanf("%lld %lld %lld",&num1,&num2,&num3);
        sum = num1 + num2 + num3;
        printf("%lld\n",sum / 2);

    }
    return 0;
}

