#include <cstdio>

using namespace std;

int main()
{
    double a,b;    
    while(scanf("%lf %lf",&a,&b) != EOF)
    {
        if ( a == b ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
