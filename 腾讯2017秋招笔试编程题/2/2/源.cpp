//不知意义何在
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	unsigned int m1, m2;
	while (cin >> m1 >> m2)
	{
		if (m1 > 1024 || m1 < 1 || m2>1024 || m2 < 1)
		{
			cout << -1 << endl;
			continue;
		}
		unsigned int array[32];
		array[(m1 - 1) >> 5] = 1 << ((m1 - 1) % 32);
		array[(m2 - 1) >> 5] = 1 << ((m2 - 1) % 32);
		if (m1 == m2)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}