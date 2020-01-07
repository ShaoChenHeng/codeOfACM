#include <cstdio>

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 

int n;
int a,b,c,d;

int main()
{
    int a,b;    
    while(scanf("%d",&n) != EOF)
    {
        while( n -- )
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int newa,newb;
            newa = d * b;
            newb = a * d + b * c;
            int gcd_num = gcd(newa,newb);
            printf( "%d %d\n",newb/gcd_num,newa/gcd_num );
        }
    }
    return 0;
}
