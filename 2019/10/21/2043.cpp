#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isSafe(string& s)
{
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	if (s.length() < 8 || s.length() > 16) return 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] <= 'Z' && s[i] >= 'A') flag1 = 1;
		if (s[i] <= 'z' && s[i] >= 'a') flag2 = 1;
		if (s[i] <= '9' && s[i] >= '0') flag3 = 1;
		if (s[i] == '^' || s[i] == '~'||s[i]=='!'||s[i]=='@' || s[i] == '#' || s[i] == '$' || s[i] == '%') flag4 = 1;
	}
	return flag1 + flag2 + flag3 + flag4 >= 3;
}

int main()
{
	int T;
	cin >> T; string s;
	while (T--)
	{
		cin >> s;
		if (isSafe(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}