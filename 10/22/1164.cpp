#include <stdio.h>
#include <math.h>
 
// 欧拉函数法
void divide(int n)
{
    int count = 0, i;
 
    while(n%2 == 0) {
        n /= 2;
        if(++count == 1)
            printf("2");
        else
            printf("*2");
    }
 
    for(i=3; i*i<=n; i+=2) {
        if(n%i == 0) {
            n /= i;
            if(++count == 1)
                printf("%d", i);
            else
                printf("*%d", i);
            while(n%i == 0) {
                n /= i;
                printf("*%d", i);
            }
        }
    }
    if(n != 1) {
        if(++count == 1)
            printf("%d", n);
        else
            printf("*%d", n);
    }
    printf("\n");
}
 
int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
        divide(n);
 
    return 0;
}
