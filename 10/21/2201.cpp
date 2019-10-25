#include <stdio.h>
int main() 
{
    double n, m;
    while (scanf("%lf%lf", &n, &m)!=EOF) {
        printf("%.2lf\n", 1/n);
    }
    return 0;
}
