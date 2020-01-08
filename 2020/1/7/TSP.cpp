#include <bits/stdc++.h>
#define q 0.98

using namespace std;

int n;
double f1, f2;
struct city
{
    int x, y;
} a[1000];
int city_list[100], city_list_copy[100];

double distance( city a, city b )
{
    return sqrt( ( a.x - b.x ) * 1.0 * ( a.x - b.x ) + ( a.y - b.y ) * 1.0 * ( a.y - b.y ) );
}

void init()
{
    for ( int i = 1; i <= n; i ++ ) city_list[i] = i;
}

double path_len( int type )
{
    double path = 0;
    if ( type == 1 )
    {
        for ( int i = 1; i < n; i ++ )
        {
            path += distance( a[city_list[i]], a[city_list[i + 1]] );
        }
        path += distance( a[city_list[1]], a[city_list[n]] );
    }
    else if ( type == 2 )
    {
        for ( int i = 1; i < n; i ++ )
        {
            path += distance( a[city_list_copy[i]], a[city_list_copy[i + 1]] );
        }
        path += distance( a[city_list_copy[1]], a[city_list_copy[n]] );
    }
    //printf("path = %lf\n",path);
    return path;
}

void creat_new()
{

    int pos1 =  (rand() % (n - 1 + 1))+ 1;
    int pos2 =  (rand() % (n - 1 + 1))+ 1;
    //int pos2 =  n * r2 ;
    //printf("pos1 = %d ",pos1);
    //printf("pos2 = %d\n",pos2);
    int temp = city_list[pos1];
    city_list[pos1] = city_list[pos2];
    city_list[pos2] = temp;
    //for ( int i = 1; i <= n; i ++ ) printf("%d ", city_list[i]);
    //printf("\n");
}

void SA()
{
    double t = 6000;
    while ( t > 1e-18 )
    {
        for ( int i = 0; i < 1000; i ++ )
        {
            memcpy( city_list_copy, city_list, sizeof(city_list));
            
            /* for ( int i = 1; i <= n; i ++ ) printf("%d ", city_list_copy[i]);
            printf("\n"); */
            creat_new();
            f1 = path_len( 1 ); // city_list
            f2 = path_len( 2 ); //city_list_copy
            double df = f1 - f2;
            // /printf("df r= %lf",df);
            if ( df >= 0 )
            {
                double r = (( double )rand()) / ( RAND_MAX );
                if ( exp( -df / t ) <= r )
                {
                    memcpy( city_list, city_list_copy, sizeof(city_list_copy));
                }

            }    
        }
        t *= q;        
    }
}

void solve()
{
    init();
    SA();
    SA();
    SA();
    printf("%.2lf",path_len(1));
}

int main()
{
    srand(10000007); 
    scanf("%d",&n);
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    //printf("hello\n");
    solve();

    return 0;
}
