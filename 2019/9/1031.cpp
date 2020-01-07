#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N,M,K;
double s;
//他得到的是：N人投票支持M个设计元素（如ACM-ICPC徽标、计算机科学界的大牌、知名图表等）。
//每个人都给每个元素分配了一些满足感。
//然而，XKA只能在他的设计中加入K（<=M）元素。他需要你为他挑选k个元素，这样总的满意度最大化。

//对于每个测试用例，在一行中打印您建议xka考虑的k个元素的索引，以便最大限度地提高满意度。如果有多个解决方案，
//则必须输出具有最小索引的解决方案。索引从1开始，必须按非递增顺序打印。两个相邻索引之间必须正好有一个空格，并且在行尾没有多余的空格。 
struct element
{
    int num,sum;
} a[100000];

bool compare(element a, element b)
{
    return (a.num > b.num);
}

bool compare2(element a, element b)
{
    return (a.sum >= b.sum);
}

int main()
{
    while( ~scanf("%d%d%d",&N,&M,&K) )
    {
        for ( int i = 0; i < M; i++ )
        {
            a[i].num = 0;
            a[i].sum = i + 1;
        }
        for ( int i = 0; i < N; i ++ )
        {
            for ( int j = 0; j < M; j++ )
            {
                scanf("%lf",&s);
                a[j].num += s;
            }
        }
        sort(a,a+M,compare);
        sort(a,a+N,compare2);

        for ( int i = 0; i < K-1; i++ )
        {
            printf("%d ",a[i].sum);
        }
        printf("%d\n",a[K-1].sum);
    }

    return 0;
}
