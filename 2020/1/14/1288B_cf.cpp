#include <bits/stdc++.h>

using namespace std;

int T;
long long int a, b;


int main()
{
    scanf("%d", &T);
    while ( T -- )
    {
        long long int cnt = 0;
        scanf("%lld %lld", &a, &b);
         
        //long long int pos = 1, temp = 0;
        /* for (long long  int  i = 1; i <= a; i ++ )
        {
            for ( long long int j = 1; j <= b; j ++ )
            {
                
                pos = cal(j);
                //printf("i = %lld j = %lld\n",i, j);
                //printf("pos = %lld\n",pos);
                //printf("1 = %lld ",(i+1) * (j + 1) - 1);
                //printf( "2 = %lld\n",i * pos * 10 + j );
                
                if ( (i + 1) * (j + 1) - 1== i * pos + j )
                {
                    cnt ++;
                    printf("i = %lld j = %lld\n",i, j);
                } 
            }
        
        }   */
        long long int j = 9;
        while ( j <= b )
        {
            j *= 10;
            j += 9;
            cnt ++;
        }
        printf("%lld\n",cnt * a);
    }

    return 0;
}
