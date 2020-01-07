#include <bits/stdc++.h>

using namespace std;

int n,k;
string ss;
char model[100];

int main()
{   
    long long int sum = 0;
    int is_succession = 0;
    scanf("%d %d",&n, &k);
    cin >> ss;
    getchar();

    for ( int i = 0; i < k; i ++ )
    {
        scanf("%c",&model[i]);
        getchar();
    }

    long long int length = 0;
    int flag = 0;
    for ( int i = 0; i < n; i ++ )
    {
        flag = 0;
        for ( int j = 0; j < k; j ++ )
        {
            if ( ss[i] == model[j] )
            {
                length ++;
                flag = 1;
            }
        }
        
        if ( flag == 0 ) is_succession = 0;
        else is_succession = 1;

        if ( is_succession == 0 ) 
        {
            sum += ( ( 1 + length ) * length / 2);
            length = 0;
        }
        //printf("length = %d\n",length);
    }
    if ( is_succession   ) sum += ( ( 1 + length ) * length / 2);
    
    printf("%lld\n",sum);

    return 0;
}
