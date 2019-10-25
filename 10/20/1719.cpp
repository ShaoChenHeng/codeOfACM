#include<cstdio>
using namespace std;
int main()
{
	int n,x,y;
	while(scanf("%d",&n) != EOF)
	{
		n += 1;
		x = y = 0;
        while( n % 2 == 0 )
        {
        	n /= 2;
        	x ++;
        }
        while( n % 3 == 0 )
        {
        	n /= 3;
        	y ++;
        }
        if( n == 1 && ( x > 0 || y > 0 ))//判断n是否是只由2或者3为因子组成的。(1不计入) 
           printf("YES!\n");
        else 
           printf("NO!\n");
	}
	return 0;
}
