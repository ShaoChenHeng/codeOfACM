#include <cstdio>
using namespace std;
 
int main()
{
    int a[35] = {0, 1, 3, 5};
    for(int i = 4; i <= 30; i++) a[i] = a[i-1] + 2 * a[i-2];
 
    int t, n;
 
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
 
    return 0;
}
