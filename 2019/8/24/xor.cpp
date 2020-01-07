#include <cstdio>
using namespace std;
 
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n != 0)
	{
		int present_number,result = 0;//0与任何非零数n相异或均得到n
		while (n--)
		{
            scanf("%d",&present_number);
			result ^= present_number;
		}
		printf("%d\n",result);
	}
 
	return 0;
}
