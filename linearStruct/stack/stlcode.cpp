#include <bits/stdc++.h>

using namespace std;

//声明了一个栈
stack<int> stk;

/*
stk.empty() 
stk.push(num) 
stk.pop();
stk.top()
*/

int main()
{
    int n;
    scanf("%d",&n);
    int cmd, num;
    //对一个栈进行n次操作
    //0压 1弹 2返回栈顶
    while ( !stk.empty() ) stk.pop();
    for ( int i = 0; i < n; i ++ )
    {
        scanf("%d",&cmd);
        if ( cmd == 0 ) 
        {
            scanf("%d",&num);
            stk.push(num);
        }
        else if ( cmd == 1 ) stk.pop();
        else if ( cmd == 2 ) 
        {
            int item = stk.top();
            printf("%d\n",item);
        }
    }
    return 0;
}
