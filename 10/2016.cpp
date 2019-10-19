#include <cstdio>

#define INF 100000
using namespace std;

int n;
int a[120];

int main()
{
	while ( scanf("%d",&n) != EOF && n)
	{
        int _min = INF;
        int num;
        int pos;
        for ( int i = 0; i < n; i++ ) 
        {
            scanf("%d",a+i);
            if ( a[i] < _min ) 
            {
                _min = a[i];
                pos = i;
            }
        }
        int temp = a[pos];
        a[pos] = a[0];
        a[0] = temp;
        for (int i = 0; i < n-1; i ++  ) printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
	} 
	return 0;
}
