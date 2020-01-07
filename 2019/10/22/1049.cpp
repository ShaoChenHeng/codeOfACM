#include <iostream>
 
using namespace std;
 
int main()
{
    int d, u, n;
    int time,len;
    while (cin >> n >> u >> d && (u + d + n)) 
    {
        len = time = 0;
        while (len < n) 
        {
            time ++;
            if (time % 2 == 1) len += u;
            else len -= d;
        }
        cout << time << endl;
    }
    return 0;
}
