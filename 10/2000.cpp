#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    char ls[4];
    while(scanf("%c%c%c",&ls[0],&ls[1],&ls[2]) != EOF)
    {
        getchar();
        sort(ls,ls+3);
        printf("%c ",ls[0]);
        printf("%c ",ls[1]);
        printf("%c\n",ls[2]);
    }
    return 0;
}
