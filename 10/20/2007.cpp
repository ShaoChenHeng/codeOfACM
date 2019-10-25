#include <iostream>
#include <cmath>
using namespace std;
typedef struct point{
 int x, y;
}point;
point polygon[101];

double areaGmty ( int num )
{
       double area = 0;
       for ( int i = 0; i < num; ++ i )
       {
              area += ( polygon[i].x * polygon[(i+1)%num].y ) - (polygon[(i+1)%num].x * polygon[i].y);
       }
       return area;
} 
int main ()
{
    int N;
    while ( scanf ( "%d",&N ), N )
    {
          for ( int i = 0; i != N; ++ i )
          {
                scanf ( "%d%d", &polygon[i].x,&polygon[i].y ); 
          } 
          double area = areaGmty ( N ) / 2.0;
          printf ( "%.1lf\n",area );
    }
    return 0; 
} 
