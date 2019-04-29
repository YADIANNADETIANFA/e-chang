#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int base[4];
	base[3] = 1;
	base[2] = base[3]*25+1;
	base[1] = base[2]*25+1;
	base[0] = base[1] * 25 + 1;
	while (cin >> s)
	{
		int len = s.size();//别用strlen，用容器该用的东西
		unsigned int index = 0;
		for (int i = 0; i < len; ++i)
		{
			index += (s[i] - 'a')*base[i]+1;
		}
		cout << index - 1 << endl;
	}
	return 0;
}