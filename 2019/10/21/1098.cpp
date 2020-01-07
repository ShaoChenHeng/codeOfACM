#include <iostream> 
 
using namespace std;
 
int main()
{
    int k, a;
    int i;
    while (cin >> k) 
    {
        for (i = 1; i <= 65; i++) 
        {
            if ( (18+k*i) % 65 == 0) { a = i; break;}
        }
        if (i == 66) puts("no");
        else printf("%d\n", a);
    }
 return 0;
}
