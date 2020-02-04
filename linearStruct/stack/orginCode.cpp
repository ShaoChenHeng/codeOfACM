#include <bits/stdc++.h>
#define N 100000
using namespace std;

int stk[N];
int point;

bool stack_empty()
{
    if ( point == 0 ) return true;
    return false;
}

void stack_push( int num )
{
    point ++;
    stk[point] = num;
}

void stack_pop()
{
    if ( stack_empty() ) printf("underflow\n");
    else point --;
}

int stack_top()
{
    return stk[point];
}

void stack_clear()
{
    point = 0;
}

int main()
{
    point = 0;
    int n;
    scanf("%d",&n);
    int cmd, num;
    //对一个栈进行n次操作
    //0压 1弹 2返回栈顶
    stack_clear();
    for ( int i = 0; i < n; i ++ )
    {
        scanf("%d",&cmd);
        if ( cmd == 0 ) 
        {
            scanf("%d",&num);
            stack_push(num);
        }
        else if ( cmd == 1 ) stack_pop();
        else if ( cmd == 2 ) 
        {
            int item = stack_top();
            printf("%d\n",item);
        }
    }

    return 0;
}
