#include <cstdio>

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 

int main()
{
    int a,b;    
    while(scanf("%d%d",&a,&b) != EOF)
    {
        printf("%d",gcd(a,b));
    
    }
    return 0;
}
