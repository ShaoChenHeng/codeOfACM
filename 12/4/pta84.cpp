#include <bits/stdc++.h>

using namespace std;

int arr[21][21];
int n, cnt;


void bfs(int x, int y, int direction_x, int direction_y, int num)
{

    if ( num  == n * n + 1)  return;

 //   printf("x = %d y = %d\n", x, y);
	if ( arr[x][y] != 0|| x > n || y  > n || y  <= 0 || x  <= 0 )  
	{
        x -= direction_x;
        y -= direction_y;
    	if ( direction_x == 0 && direction_y == 1 )
		{

			direction_x = 1;
			direction_y = 0;
 			bfs( x + direction_x, y + direction_y, direction_x, direction_y, num  );
		}
		else if ( direction_x == 1 && direction_y == 0 )
		{
			direction_x = 0;
			direction_y = -1;
 			bfs( x + direction_x, y + direction_y, direction_x, direction_y, num  );
		}
		else if ( direction_x == 0 && direction_y == -1 )
		{
			direction_x = -1;
			direction_y = 0;
 			bfs( x + direction_x, y + direction_y, direction_x, direction_y, num );
		}
		else if ( direction_x == -1 && direction_y == 0 )
		{
			direction_x = 0;
			direction_y = 1;
 			bfs( x + direction_x, y + direction_y, direction_x, direction_y, num );
		}
	}
	else
	{
        cnt ++;
		arr[x][y] = num;
        //printf("num = %d\n",num);
		bfs( x + direction_x, y + direction_y, direction_x, direction_y, num + 1 );
	}
}

int main()
{
	scanf("%d",&n);
    for ( int i = 1; i <= n + 3; i ++ )
    {
        for ( int j = 1; j <= n + 3; j ++ ) arr[i][j] = 0;
    }
    cnt = 0;
	bfs(1,1,0,1,1);
	for ( int i = 1; i <= n; i ++ )
	{
		for ( int j = 1; j <= n; j ++ ) 
		{
			printf("%3d",arr[i][j] );
            //if ( i != n ) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
